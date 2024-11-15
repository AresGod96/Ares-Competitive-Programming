const
        maxN=400000;
type task=record t1,t2,d:longint; end;
var a:array[1..2*maxN+1] of task;
    n,i:longint;

procedure sort(L,R:longint);
var i,j,x:longint;
    tmp:task;
begin
        i:=L; j:=R; x:=a[(L+R) shr 1].d;
        repeat
                while a[i].d > x do inc(i);
                while x > a[j].d do dec(j);
                if i<=j then
                begin
                        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
                        inc(i); dec(j);
                end;
        until i>j;
        if i<R then sort(i,R);
        if L<j then sort(L,j);
end;

procedure solve;
var aa,bb,res,i:longint;
begin
        aa:=0; bb:=0;
        res:=0;
        for i:=1 to 2*n do
        begin
                if aa=n then inc(res,a[i].t2);
                if bb=n then inc(res,a[i].t1);
                if (aa<n) and (bb<n) then
                begin
                        if a[i].t1<a[i].t2 then
                        begin
                                inc(aa); inc(res,a[i].t1);
                        end
                        else
                        begin
                                inc(bb); inc(res,a[i].t2);
                        end;
                end;
        end;
        writeln(res);
end;
//
begin
        readln(n);
        for i:=1 to 2*n do
        begin
                readln(a[i].t1,a[i].t2);
                a[i].d:=abs(a[i].t1-a[i].t2);
        end;
        sort(1,n shl 1);
        solve;
        readln
end.
