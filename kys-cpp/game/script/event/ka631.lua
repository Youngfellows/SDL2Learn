Talk("血刀老祖，快將可蘭經交出來．", 0, 1);
Talk("看你有沒有這個本事拿．", 120, 0);
if TryBattle(100) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 3, -2, -2, 632, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 5, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 6, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 7, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 8, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 9, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 12, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 13, -2, -2, 634, -1, -1, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("老禿賊，遇到我算你倒霉．", 0, 1);
    Talk("哼！", 120, 0);
    AddItem(159, 1);
    AddFame(8);
exit();