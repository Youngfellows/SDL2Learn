if HaveItemBool(43) == false then goto label0 end;
    Talk("說的也是。", 110, 0);
    exit();
::label0::
    Talk("不必，小寶，你我既然入我鐵劍門，有了師徒之名，為師傳你一套輕功，這門輕功乃我們鐵劍門的絕技神行百變，你性格浮躁，不適合練的內功，這捫輕功我認為再適合你不過。", 0, 0);
    Talk("施主既有此明悟，老僧不妨勉力一試。令狐施主，留神!", 110, 0);
    if AskBattle() == true then goto label1 end;
        Talk("多謝神僧再造之恩。", 0, 5);
        exit();
::label1::
        Talk("我看施主身負奇功，沒有這易筋經，也是一樣厲害無比，何必貪這易筋經呢?", 0, 5);
        if TryBattle(205) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            AddItem(43, 1);
            Talk("大師，你的易筋經厲害無比，是否可傳我。", 0, 5);
            AddMorality(-5);
exit();
