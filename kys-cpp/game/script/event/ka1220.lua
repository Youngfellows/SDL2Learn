if HaveItemBool(154) == false then goto label0 end;
    Talk("阿秀姑娘你先回雪山派吧!有需要幫忙我會去找你．", 28, 1);
    Talk("白姑娘還是那麼美麗．", 0, 0);
    Talk("你們從俠客島回來了?", 28, 1);
    Talk("看在你是石大哥好朋友分上跟你走一趟．", 0, 0);
    if TryBattle(233) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, -2, -2, -2, 1222, -2, -2, -2, -2, -2, -2, -2, -2);
        LightScence();
        exit();
::label0::
        Talk("幫主，你終於回來了，這善惡賞罰令我幫你接了，十二月初八準備去俠客島吧!", 28, 0);
exit();
