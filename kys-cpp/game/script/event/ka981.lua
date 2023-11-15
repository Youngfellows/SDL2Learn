if isUsingItem(174) == true then goto label0 end;
    exit();
::label0::
    if CheckEnoughMoney(1000) == true then goto label1 end;
        Talk("小寶好像在皇宮混著還不錯．", 162, 0);
        exit();
::label1::
        Talk("韋兄弟，關於四十二章經．．．", 162, 0);
        Talk("哎呀，你看看 ，我口袋破了一個洞，我的銀子全都掉了．", 0, 0);
        Talk("這點小錢，拿給我塞牙縫都不夠．", 162, 0);
        Talk("四十二章經歐，我打聽到的情況是鰲拜都將此書隨身攜帶，想要偷偷拿走應該是不可能的．", 0, 0);
        Talk("這個情報有跟沒有都一樣，還有呢?", 162, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 31, 0, -2, -1, -1, 982, -1, -1, -1, -2, -2, -2);
        AddItemWithoutHint(174, -1000);
        LightScence();
        Talk("只有這樣．．．", 0, 0);
exit();
