Talk("少俠，老夫聽說你獨自攻上這黑木崖來，特別率我五岳派門徒趕上來幫你．東方不敗那魔頭呢？", 19, 0);
Talk("唉！你們怎麼跟電影劇情一樣，事情都結束後才出現．東方不敗那個變態家伙，已經被我”干掉”了．", 0, 1);
Talk("真是如此！少俠又替我武林正派立了一項大功．", 19, 0);
Talk("那里，那里．", 0, 1);
Talk("那不知少俠是否有看到一本書？", 19, 0);
Talk("什麼書？", 0, 1);
Talk("”笑傲江湖”！", 19, 0);
Talk("當然有啊！我辛苦了半天，還不都是為了它．任老頭將它送給我了．", 0, 1);
Talk("這又是另一項功勞了．少俠真當為我武林同道所敬仰．此書乃是我五岳劍派許多前輩當年拼命所得到的，後來不幸被魔教奪去．我五岳派這幾年發奮圖強，與魔教周旋到底，為的就是將此書奪回．想不到今日少俠大顯神威，從魔教手中將此書奪回，我五岳派全體上下無限感激．現在就請少俠將此書還與我五岳派．", 19, 0);
Talk("＜說了半天，原來也是想要  ”笑傲江湖”這本書＞不過據我所知，這本書的原主人也不是五岳劍派的人．你們前輩只是暫時得到過．今天，我的任務就是要將這些書送回原處，你們以後也不用再為此煩心．更何況這書也不是你們想像中的什麼高深武功秘笈，它只不過是本故事書罷了．", 0, 1);
Talk("莫非，少俠是想將此書占為己有．還是你已與魔教勾結了？", 19, 0);
Talk("岳先生，你別給我亂安罪名了．這書真的不是你們想像中的什麼高深武功秘笈，它只不過是本故事書罷了．", 0, 1);
Talk("看來少俠入魔已深，非得要逼我們動手不可．", 19, 0);
Talk("我看是你岳不群入魔已深．那日嵩山大會上我就有點被”耍”的感覺．今天，你為了搶這本”笑傲江湖”又想不擇手段．今日你怎會突然出現，分明就是早已算計好的，想等我跟東方不敗鶴蚌相爭，你好來個漁翁得利．我看你不是”君子劍”，分明是個”偽君子”！", 0, 1);
Talk("你．．．你說什麼！", 19, 0);
if InTeam(35) == false then goto label0 end;
    Talk("師父，別再執迷下去了．這書的確不是武功秘笈，只是一本普通的書．", 35, 1);
::label0::
    Talk("岳先生，回頭是岸．", 0, 1);
    Talk("別說這麼多的廢話，五岳派的人聽著，給我殺，今日不留一個活口．", 19, 0);
    if TryBattle(56) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, 61, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 62, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 63, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 64, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 65, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 66, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 67, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 68, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 69, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 70, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 71, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 72, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 73, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 74, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 75, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 76, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 77, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 78, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 79, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 80, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 81, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 83, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 84, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 85, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Talk("五岳派的各位，今日多有冒犯之處，請多包涵．", 0, 1);
        Talk("哼！我們走．", 19, 0);
        DarkScence();
        ModifyEvent(-2, 56, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 57, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 58, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 59, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 60, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Talk("想不到在找尋這本書的過程中，讓我看到人性中為了爭權奪利所展現的丑陋面．不管是正派中的左冷禪與岳不群，還是邪派中的任我行與東方不敗，都是一樣的．", 0, 1);
        ModifyEvent(-2, 87, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 88, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 89, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 90, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 91, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 92, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 93, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(31, 0, -2, -2, 329, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(31, 1, -2, -2, 329, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(29, 0, -2, -2, 330, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(29, 1, -2, -2, 330, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(58, 10, -2, -2, 331, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(58, 11, -2, -2, 331, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(57, 0, -2, -2, 332, -1, -1, -2, -2, -2, -2, -2, -2);
        ModifyEvent(57, 1, -2, -2, 332, -1, -1, -2, -2, -2, -2, -2, -2);
        AddFame(12);
exit();