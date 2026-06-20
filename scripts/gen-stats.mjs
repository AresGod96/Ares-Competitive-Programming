#!/usr/bin/env node
// Regenerates the README statistics charts (assets/stats-sources.svg,
// assets/stats-tiers.svg) from the current state of the repo.
//
// Zero dependencies. Run from the repo root:
//   node scripts/gen-stats.mjs
//
// It scans each source directory for .cpp solutions and reads the "Difficulty"
// line of every problem README to tally solved.ac tiers, then writes two
// self-contained SVG cards that GitHub renders inline in the README.

import { readFileSync, writeFileSync, readdirSync, statSync, mkdirSync } from "node:fs";
import { join, dirname } from "node:path";
import { fileURLToPath } from "node:url";

const ROOT = join(dirname(fileURLToPath(import.meta.url)), "..");
const ASSETS = join(ROOT, "assets");

// --- Source directories, in canonical display order -------------------------
const SOURCES = [
  ["codeforces", "Codeforces"],
  ["boj", "BOJ"],
  ["gym", "Gym"],
  ["olympiads", "Olympiads"],
  ["vnoj", "VNOJ"],
  ["spoj", "SPOJ"],
  ["icpc", "ICPC"],
  ["gcj", "GCJ"],
  ["free-contest", "Free Contest"],
  ["cses", "CSES"],
];

// solved.ac tier groups + their official colors.
const TIERS = [
  ["bronze", "Bronze", "#ad5600"],
  ["silver", "Silver", "#435f7a"],
  ["gold", "Gold", "#ec9a00"],
  ["plat", "Platinum", "#27e2a4"],
  ["dia", "Diamond", "#00b4fc"],
  ["ruby", "Ruby", "#ff0062"],
];

// Distinct palette for the source chart.
const SOURCE_COLORS = [
  "#5b8def", "#ef6f6c", "#f2b134", "#4cb944", "#9b5de5",
  "#00bbf9", "#f15bb5", "#22d3ee", "#fb923c", "#a3a3a3",
];

const SKIP_DIRS = new Set([".git", ".gitnexus", ".serena", ".vscode", "node_modules", "boj-icon", "assets"]);

// --- Scanning ----------------------------------------------------------------
function walk(dir, onFile) {
  let entries;
  try {
    entries = readdirSync(dir);
  } catch {
    return;
  }
  for (const name of entries) {
    if (SKIP_DIRS.has(name)) continue;
    const full = join(dir, name);
    let st;
    try {
      st = statSync(full);
    } catch {
      continue;
    }
    if (st.isDirectory()) walk(full, onFile);
    else onFile(full);
  }
}

function countCpp(srcDir) {
  let n = 0;
  walk(join(ROOT, srcDir), (f) => {
    if (f.endsWith(".cpp")) n += 1;
  });
  return n;
}

function tallyTiers() {
  const counts = Object.fromEntries(TIERS.map(([key]) => [key, 0]));
  walk(ROOT, (f) => {
    if (!/README\.md$/i.test(f)) return;
    const text = readFileSync(f, "utf8");
    for (const line of text.split("\n")) {
      if (!line.includes("Difficulty")) continue;
      const m = line.match(/boj-icon\/([a-z]+)\d*\.svg/i);
      if (!m) continue;
      const token = m[1].toLowerCase();
      const group = TIERS.find(([key]) => token.startsWith(key));
      if (group) counts[group[0]] += 1;
    }
  });
  return counts;
}

// --- SVG theme ---------------------------------------------------------------
const T = {
  bg: "#0d1117",
  border: "#30363d",
  grid: "#21262d",
  title: "#f0f6fc",
  text: "#c9d1d9",
  muted: "#8b949e",
  font: "ui-sans-serif, system-ui, -apple-system, 'Segoe UI', Roboto, Helvetica, Arial, sans-serif",
};
const esc = (s) => String(s).replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;");

function niceMax(v, step) {
  return Math.max(step, Math.ceil(v / step) * step);
}

// --- Vertical bar chart: tiers ----------------------------------------------
function renderTiers(counts) {
  const data = TIERS.map(([key, label, color]) => ({ label, color, value: counts[key] }));
  const total = data.reduce((a, d) => a + d.value, 0);
  const W = 720, H = 360;
  const padL = 44, padR = 24, padT = 70, padB = 46;
  const plotW = W - padL - padR;
  const plotH = H - padT - padB;
  const maxV = niceMax(Math.max(...data.map((d) => d.value), 1), 5);
  const ticks = 3;
  const slot = plotW / data.length;
  const barW = Math.min(70, slot * 0.56);

  const parts = [];
  parts.push(
    `<rect x="0.5" y="0.5" width="${W - 1}" height="${H - 1}" rx="12" fill="${T.bg}" stroke="${T.border}"/>`
  );
  parts.push(
    `<text x="24" y="34" font-family="${T.font}" font-size="20" font-weight="700" fill="${T.title}">Problems by difficulty tier</text>`
  );
  parts.push(
    `<text x="24" y="55" font-family="${T.font}" font-size="13" fill="${T.muted}">${total} problems rated on the solved.ac scale</text>`
  );

  // gridlines + y labels
  for (let i = 0; i <= ticks; i++) {
    const val = (maxV / ticks) * i;
    const y = padT + plotH - (val / maxV) * plotH;
    parts.push(`<line x1="${padL}" y1="${y.toFixed(1)}" x2="${W - padR}" y2="${y.toFixed(1)}" stroke="${T.grid}"/>`);
    parts.push(
      `<text x="${padL - 8}" y="${(y + 4).toFixed(1)}" text-anchor="end" font-family="${T.font}" font-size="11" fill="${T.muted}">${val}</text>`
    );
  }

  data.forEach((d, i) => {
    const cx = padL + slot * i + slot / 2;
    const x = cx - barW / 2;
    const h = (d.value / maxV) * plotH;
    const y = padT + plotH - h;
    if (d.value > 0) {
      parts.push(`<rect x="${x.toFixed(1)}" y="${y.toFixed(1)}" width="${barW.toFixed(1)}" height="${h.toFixed(1)}" rx="4" fill="${d.color}"/>`);
      parts.push(
        `<text x="${cx.toFixed(1)}" y="${(y - 8).toFixed(1)}" text-anchor="middle" font-family="${T.font}" font-size="14" font-weight="700" fill="${T.title}">${d.value}</text>`
      );
    } else {
      parts.push(
        `<text x="${cx.toFixed(1)}" y="${(padT + plotH - 8).toFixed(1)}" text-anchor="middle" font-family="${T.font}" font-size="13" fill="${T.muted}">0</text>`
      );
    }
    parts.push(
      `<text x="${cx.toFixed(1)}" y="${(padT + plotH + 22).toFixed(1)}" text-anchor="middle" font-family="${T.font}" font-size="13" fill="${d.color}" font-weight="600">${esc(d.label)}</text>`
    );
  });

  return svg(W, H, parts.join("\n  "));
}

// --- Horizontal bar chart: sources ------------------------------------------
function renderSources(rows) {
  const data = [...rows].sort((a, b) => b.value - a.value);
  const total = data.reduce((a, d) => a + d.value, 0);
  const W = 720;
  const padT = 70, padB = 20, rowH = 30, labelW = 116, valW = 44;
  const H = padT + padB + data.length * rowH;
  const trackX = labelW;
  const trackW = W - labelW - valW - 24;
  const maxV = niceMax(Math.max(...data.map((d) => d.value), 1), 10);

  const parts = [];
  parts.push(`<rect x="0.5" y="0.5" width="${W - 1}" height="${H - 1}" rx="12" fill="${T.bg}" stroke="${T.border}"/>`);
  parts.push(`<text x="24" y="34" font-family="${T.font}" font-size="20" font-weight="700" fill="${T.title}">Problems by source</text>`);
  parts.push(`<text x="24" y="55" font-family="${T.font}" font-size="13" fill="${T.muted}">${total} solved problems across ${data.length} sources</text>`);

  data.forEach((d, i) => {
    const yMid = padT + rowH * i + rowH / 2;
    const barH = 16;
    const y = yMid - barH / 2;
    const w = Math.max(2, (d.value / maxV) * trackW);
    parts.push(`<rect x="${trackX}" y="${y.toFixed(1)}" width="${trackW.toFixed(1)}" height="${barH}" rx="4" fill="${T.grid}"/>`);
    parts.push(`<rect x="${trackX}" y="${y.toFixed(1)}" width="${w.toFixed(1)}" height="${barH}" rx="4" fill="${d.color}"/>`);
    parts.push(
      `<text x="${trackX - 10}" y="${(yMid + 4).toFixed(1)}" text-anchor="end" font-family="${T.font}" font-size="13" fill="${T.text}">${esc(d.label)}</text>`
    );
    parts.push(
      `<text x="${(trackX + w + 8).toFixed(1)}" y="${(yMid + 4).toFixed(1)}" font-family="${T.font}" font-size="13" font-weight="700" fill="${T.title}">${d.value}</text>`
    );
  });

  return svg(W, H, parts.join("\n  "));
}

function svg(w, h, body) {
  return `<svg xmlns="http://www.w3.org/2000/svg" width="${w}" height="${h}" viewBox="0 0 ${w} ${h}" role="img">
  ${body}
</svg>
`;
}

// --- Main --------------------------------------------------------------------
const sourceRows = SOURCES.map(([dir, label], i) => ({
  dir,
  label,
  value: countCpp(dir),
  color: SOURCE_COLORS[i % SOURCE_COLORS.length],
}));
const tierCounts = tallyTiers();

mkdirSync(ASSETS, { recursive: true });
writeFileSync(join(ASSETS, "stats-sources.svg"), renderSources(sourceRows));
writeFileSync(join(ASSETS, "stats-tiers.svg"), renderTiers(tierCounts));

const totalProblems = sourceRows.reduce((a, r) => a + r.value, 0);
const totalRated = TIERS.reduce((a, [k]) => a + tierCounts[k], 0);

// Keep the README summary line in sync with the generated charts.
const readmePath = join(ROOT, "README.md");
try {
  const before = readFileSync(readmePath, "utf8");
  const after = before
    .replace(/\*\*\d+ solved problems\*\* across \d+ sources/, `**${totalProblems} solved problems** across ${sourceRows.length} sources`)
    .replace(/cover the \*\*\d+ problems\*\* rated/, `cover the **${totalRated} problems** rated`);
  if (after !== before) {
    writeFileSync(readmePath, after);
    console.log("Updated README.md summary line");
  }
} catch {
  // README is optional from the script's perspective.
}

console.log(`Sources: ${sourceRows.map((r) => `${r.label}=${r.value}`).join(", ")}`);
console.log(`Tiers:   ${TIERS.map(([k, l]) => `${l}=${tierCounts[k]}`).join(", ")}`);
console.log(`Totals:  ${totalProblems} problems, ${totalRated} rated`);
console.log(`Wrote assets/stats-sources.svg and assets/stats-tiers.svg`);
