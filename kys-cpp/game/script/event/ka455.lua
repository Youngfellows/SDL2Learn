Talk("外敵來襲，重陽宮恕不接客", 95, 0);
if AskBattle() == true then goto label0 end;
    Talk("真是不巧，那只好改天再登門拜訪了．", 0, 1);
    exit();
::label0::
    Talk("這熱鬧我可不能不瞧。", 0, 1);
    Talk("師兄，咱們也湊個熱鬧。", 51, 1);
    if TryBattle(73) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, 1, -2, -2, 456, -1, -1, 6114, 6114, 6114, -2, 31, 48);
        ModifyEvent(-2, 2, -2, -2, 456, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 3, -2, -2, 456, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 4, -2, -2, 456, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 5, -2, -2, 456, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 6, -2, -2, 456, -1, -1, -2, -2, -2, -2, -2, -2);
        LightScence();
        Talk("霍都和達爾巴，全真教一定遇上大麻煩了！", 0, 0);
        AddFame(1);
exit();
