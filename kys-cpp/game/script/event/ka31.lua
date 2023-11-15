Talk("苗大俠，你要照顧好自己，等我從毒手藥王那求取到解藥回來幫你醫治．", 0, 1);
if HaveItemBool(137) == false then goto label0 end;
    exit();
::label0::
    if InTeam(2) == false then goto label1 end;
        Talk("我知道了，這解藥應該可以治他的雙眼。", 2, 0);
        AddItem(137, 1);
exit();
::label1::
exit();
