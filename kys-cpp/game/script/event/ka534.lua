Talk("公子是否有破解這”珍瓏”的方法了？", 52, 0);
if InTeam(49) == true then goto label0 end;
    Talk("晚輩棋力不佳，否則我倒也想試一試．", 0, 1);
    Talk("可惜，可惜，難道世上無人能解開此”珍瓏”嗎？", 52, 0);
    exit();
::label0::
    LeaveTeam(44);
    Talk("晚輩棋力不佳，不過我試試看好了．", 0, 1);
    Talk("慢著，我們老大也有興趣，你們讓開。", 44, 0);
    Talk("你這人說話真沒道理，明明是我們先來的，你們總知道先來后到的規矩吧。", 0, 1);
    Talk("哈，小兄弟，跟你將規矩的話我們就不叫“四大惡人”了。", 56, 0);
    if TryBattle(174) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("老大，不好對付啊！", 14, 0);
        Talk("哼，我們走！", 71, 1);
        Talk("公子請．", 52, 0);
        DarkScence();
        LightScence();
        Talk("嗯．．．前去無路，後有追兵，正也不是，邪也不是，那可難也！．．．＜咦，棋局上的白子黑子似乎都化做了各派高手，東一堆使劍，西一堆使拳，你圍住我，我圍住你，互相糾纏不清的廝殺．．．．．．．我方白色的人馬被黑色各派高手給圍住了，左沖右突，始終殺不出重圍．．．．＞難道我天命已盡，一切枉費心機了．我這樣努力的找尋”十四天書”，終究要化作一場夢！時也命也，夫復何言？我不如死了算了．", 0, 1);
        Talk("閃開!讓專業的來", 49, 1);
        Talk("胡鬧，胡鬧，你自填一氣，自己殺死一塊白棋，那有這等的下法．", 52, 0);
        Talk("咦！難道竟是這樣？前輩你看，白棋故意擠死了一大塊後，接下來就好下多了．", 0, 1);
        Talk("這．．這．．．這”珍瓏”竟然解了，原來關鍵在於第一著的怪棋．這局棋原本糾纏於得失勝敗之中，以至無可破解，小和尚這一著不著意於生死，更不著意於勝敗，反而勘破了生死，得到解脫．．．．．", 52, 0);
        Talk("賽對了哈哈", 49, 1);
        Talk("為啥我的同伴都是一堆賽郎．", 0, 1);
        Talk("神僧天賦英才，可喜可賀．請入屋內．", 52, 0);
        Talk("來吧!", 49, 1);
        Talk("一定又得到啥神功．", 0, 1);
        DarkScence();
        ModifyEvent(-2, 1, 1, 1, -1, -1, -1, 6486, 6486, 6486, -2, -2, -2);
        ModifyEvent(-2, 2, 1, 1, -1, -1, -1, 6450, 6450, 6450, -2, -2, -2);
        LeaveTeam(49);
        LightScence();
        SubMapViewFromTo(17, 28, 24, 19);
        Play2Amination(1, 6486, 6520, 2, 6450, 6484, 44);
        Play2Amination(1, 6486, 6520, 2, 6450, 6484, 44);
        Play2Amination(1, 6486, 6520, 2, 6450, 6484, 25);
        SubMapViewFromTo(24, 19, 17, 28);
        DarkScence();
        SetSubMapLayerData(-2, 1, 22, 24, 1532);
        SetSubMapLayerData(-2, 1, 22, 23, 1534);
        SetSubMapLayerData(-2, 1, 23, 24, 0);
        SetSubMapLayerData(-2, 1, 24, 24, 1536);
        SetSubMapLayerData(-2, 1, 24, 23, 1538);
        ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 1, 1, 1, -1, -1, -1, 6524, 6524, 6524, -2, -2, -2);
        ModifyEvent(-2, 2, 1, 1, 536, -1, -1, 6522, 6522, 6522, -2, -2, -2);
        ModifyEvent(-2, 3, 1, 1, -1, -1, -1, 6342, 6342, 6342, -2, -2, -2);
        LightScence();
        Talk("奇怪，怎麼進去這麼久．．我也進去看看好了．", 0, 1);
        Talk("蘇星河怎么不在？", 46, 0);
        Talk("蘇先生正和我兄弟在里面。", 0, 1);
        Talk("哦？不好，不會是老家伙……", 46, 0);
        Talk("喂，你要干什么？你不能進去。", 0, 1);
        Talk("不怕死的小輩，連我星宿老仙的事都敢管！", 46, 0);
        if TryBattle(152) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            Talk("好險，這老妖怪一身毒物。對了，我也該進去瞧個究竟", 0, 0);
exit();