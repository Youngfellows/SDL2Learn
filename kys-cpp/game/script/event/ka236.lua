if InTeam(29) == false then goto label0 end;
    Talk("哈哈，先處理我的神龍教教眾吧，等你處理完我的教眾後，我已逃離這里，後會有期．", 29, 0);
    Talk("他媽的給他跑了．", 175, 1);
    Talk("少年ㄟ，請先付錢，看一次一百倆．", 35, 5);
    Talk("我就說你這小妞怎麼不見了，原來是跟別的漢子偷偷走了，你不是會用華山劍法的那個小子嗎?", 29, 0);
    Talk("你．．．你這淫賊，你胡說什麼 我們五岳劍派同氣連枝，他是我華山派師兄，是他把我救出來的．", 35, 5);
    Talk("在下華山令狐沖，閣下就是千里獨行田伯光吧，你有沒有種跟老子打個賭，咱們來打一場，我打贏就別在為難我這儀琳師妹如何?", 29, 0);
    DarkScence();
    ModifyEvent(-2, 41, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 46, -2, -2, -2, -2, -2, 7624, 7624, 7624, -2, -2, -2);
    ModifyEvent(-2, 47, -2, -2, -2, -2, -2, 8308, 8308, 8308, -2, -2, -2);
    LightScence();
    PlayAnimation(47, 8308, 8334);
    PlayAnimation(46, 7624, 7654);
    Talk("我當然有種，我的種還比一般人大的勒，打，你是打我不過的，只要你能打贏，我放棄嚐嚐這俏尼姑．", 29, 0);
    Talk("我現在身受內傷當然不是你對手。但若是比招式不使用內力，你便不是我對手", 35, 0);
    Talk("好，我就看你如何用劍招破我的快刀．", 29, 0);
    Talk("好招，不過這不像是華山劍法．", 35, 0);
    DarkScence();
    ModifyEvent(-2, 45, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 46, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 47, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(31, 39, 0, -2, -1, -1, 181, -2, -2, -2, -2, -2, -2);
    ModifyEvent(31, 40, 0, -2, -1, -1, 181, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("小子，你知道令狐沖在哪嗎?我老田來找他較量了．", 0, 0);
    AddIQ(0, 5);
    exit();
::label0::
    Talk("這位兄弟有何貴事，是不是想請我喝酒！", 35, 0);
exit();
