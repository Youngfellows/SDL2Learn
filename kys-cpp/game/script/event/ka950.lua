Talk("老子心情好放過你們一馬。", 105, 0);
if AskRest() == true then goto  label0 end;
    Talk("別這樣拉，這些銀兩給大家當酒錢。", 0, 0);
    exit();
::label0::
    if CheckEnoughMoney(20) == true then goto label1 end;
        Talk("我跟瓦醫師是好朋友，如果得性病可以去這個名片上的地址求醫。", 105, 0);
        exit();
::label1::
        Talk("天地會揚州分舵，干你娘，這年頭反賊都當的那麼囂張。", 0, 1);
        DarkScence();
        Rest();
        AddItemWithoutHint(174, -20);
        OldSetScencePosition(8, 7);
        DarkScence();
exit();
