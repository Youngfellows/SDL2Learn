if InTeam(55) == true then goto label0 end;
    Talk("郭靖安答，你不只是我的好兄弟，也快成為我的妹夫了，哈哈", 0, 0);
    Talk("少俠武功高強，我們蒙古人甚是佩服", 137, 0);
    Talk("金刀駙馬好!", 0, 0);
    Talk("蓉兒!你別再傷心了", 137, 0);
    Talk("大哥，靖哥哥真的會當那個金刀駙馬嗎?嗚~~", 0, 0);
    Talk("我看蓉兒比那啥華箏公主美多了，我想郭兄弟也是這麼認為，只是我想郭兄弟想拒這門婚事絕也拒絕不了", 137, 0);
    Talk("那大汗對靖哥哥恩重如山，靖哥哥又怎麼忍心弗了大汗的好意", 0, 0);
    if AskJoin () == true then goto label1 end;
        exit();
::label1::
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 137, 0);
            exit();
::label2::
            Talk("蓉兒，這世上除了郭兄弟對你好，別忘了我也會對你好", 0, 0);
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            LightScence();
            Join(56);
            exit();
::label0::
            Talk("大哥，嗚~~~", 55, 0);
            Talk("舊的不去新的不來，初戀總是苦澀的，我會慢慢撫平你心中的創傷", 137, 0);
            Talk("別窩在桃花島上，跟我到處走走散散心會開心一點", 55, 0);
            Talk("蓉兒，你別再生氣了，那金刀駙馬是大汗的命令，我也沒辦法違背", 0, 0);
            Talk("我知道大汗對你有恩，但你不拒絕你就要跟那華箏公主成婚了", 55, 0);
            Talk("．．．．．．", 137, 0);
exit();
