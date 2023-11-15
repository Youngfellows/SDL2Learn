Talk("玉兒好像在雪山派闖了大禍，咱們先上雪山派看看再說．", 1, 0);
if TryBattle(237) == true then goto label0 end;
::label0::
    LightScence();
    Talk("干，跟你一起還真雖小，差點害死我這個擁有真龍天子之命的人．", 0, 0);
    Talk("幫主和副幫主都不在幫中，少俠請回吧!", 1, 0);
    Talk("擋路的小子，快讓開．", 94, 1);
    Talk("好刀法!", 0, 0);
    Talk("好武功!後面那一群大內高手就交給你，老子先走了，哈哈!", 94, 1);
    if TryBattle(238) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("大膽刁民，還不交出從宮中偷出的寶物．", 0, 0);
        ModifyEvent(85, 3, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(85, 4, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(30, 6, 1, -2, 612, -1, -1, 5166, 5166, 5166, -2, -2, -2);
exit();
