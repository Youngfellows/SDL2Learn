ModifyEvent(-2, -2, 1, -2, -1, -1, -1, 2608, 2608, 2608, -2, -2, -2);
AddItem(109, 1);
Talk("主人就在旁邊，還是別亂開他的寶箱好了", 0, 1);
PlayAnimation(-1, 5994, 6012);
Talk("如果主人是歪妹你一定照拿不誤，人正真好", 9, 1);
DarkScence();
ModifyEvent(-2, 23, -2, -2, -2, -2, -2, 8376, 8376, 8376, -2, -2, -2);
ModifyEvent(-2, 24, -2, -2, -2, -2, -2, 5900, 5900, 5900, -2, -2, -2);
LightScence();
SubMapViewFromTo(45, 19, 43, 25);
Talk("嘖嘖，這倚天劍還真是一把寶劍，怎麼有一股檀香木的香氣，啊!", 194, 0);
Talk("師父的倚天劍就被放在外面寶箱里，等下一定要拿回來", 9, 1);
Talk("趙姑娘，在下向你討幾棵花草。", 194, 0);
if TryBattle(247) == true then goto label0 end;
::label0::
    LightScence();
    Talk("大哥!我一樣飲酒食菜與大哥絕無分別，怎麼他突然昏倒，我卻沒事，難道是．．．", 194, 0);
    Talk("才得相會，如何便去？莫是嫌小女子接待太過簡慢麼？", 9, 1);
    Talk("張公子，你這是什麼功夫？便是乾坤大挪移神功嗎？我瞧也平平無奇。你喜歡我這朵珠花，送了給你便是，也不須動手強搶。", 194, 0);
    Talk("沒那麼容易", 9, 1);
    PlayAnimation(23, 8376, 8402);
    DarkScence();
    ModifyEvent(-2, 24, -2, -2, -2, -2, -2, 5902, 5902, 5902, -2, -2, -2);
    LightScence();
    Talk("趙姑娘，如果你不給我拿解藥，我可對你不客氣了。", 194, 0);
    Talk("不客氣?那我到要看看是啥不客氣法。", 9, 0);
    Talk("得罪了!", 0, 0);
    if InTeam(49) == false then goto label1 end;
        Talk(" 哼，你就算扒光我的衣服 ，我也不給你拿解藥，有種你真的扒光我的衣服。", 49, 0);
        Talk("真的不給?", 0, 0);
        Talk("哈啾!", 49, 0);
        Talk("．．．．．．", 9, 0);
::label1::
        DarkScence();
        ModifyEvent(-2, 23, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        PlayAnimation(-1, 6026, 6036);
        Talk("干你媽的，到最精采的時候，你打啥噴嚏。", 9, 1);
        Talk("靠，原來你也裝暈。", 0, 0);
        Talk("廢話，我內力深厚，怎麼可能中毒 好了，別說了，無忌兄弟，讓她生讓她生，恭喜老爺賀喜夫人。", 194, 0);
        Talk("大哥，你沒事了嗎?", 0, 0);
        Talk("嘿嘿，沒事，不過看到養眼的東西，嘖嘖。", 9, 1);
        Talk("．．．．．．", 194, 0);
        DarkScence();
        ModifyEvent(-2, 24, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(43, 72, 0, -2, -1, -1, 149, -1, -1, -1, -2, -2, -2);
        ModifyEvent(43, 73, 0, -2, -1, -1, 149, -1, -1, -1, -2, -2, -2);
        LightScence();
exit();
