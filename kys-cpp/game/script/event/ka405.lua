Talk("師父好福氣，竟住在如此奇妙的所在．", 0, 1);
Talk("你倒說說看，我這百花谷怎生好法．", 64, 0);
Talk("此處山谷向南，高山阻住了北風，想來地下又有硫磺，煤炭等類礦藏，地氣特暖．因之陽春早臨，百花先放．", 0, 1);
Talk("聰明徒弟還算有點見識．不過下次你再來時，又會有另一番風貌的．最近我正在馴養蜜蜂，雖然有點．．有點不順，但．．但我一定會想辦法讓這些小東西乖乖馴服的．", 64, 0);
Talk("這陣子老子遍游江湖各地，道聽途說了一些，沒什麼收獲，倒是見聞增廣了不少．", 0, 1);
Talk("你說你最近跑遍江湖，那你知不知道武林中有什麼新功夫問世．", 64, 0);
Talk("我是得到一些秘笈，不過功夫還不到家．", 0, 1);
Talk("來來來，跟我來玩兩招．", 64, 0);
ModifyEvent(-2, -2, -2, -2, 406, 407, -1, -2, -2, -2, -2, -2, -2);
if AskBattle() == true then goto label0 end;
    Talk("當我師父連功夫都不教我，我干麻跟你打．", 0, 1);
    exit();
::label0::
    Talk("打死人不償命．", 0, 1);
    if TryBattle(67) == false then goto label1 end;
        LightScence();
        Talk("聰明徒弟，你這是什麼功夫，教教我好不好．", 64, 0);
        Talk("我是你徒弟．哪有師父叫徒弟教師父的道理．", 0, 1);
        Talk("這樣好了，我跟你磕八個響頭，我改拜你為師，你就不是我徒弟，那你總肯教我了吧．", 64, 0);
        Talk("哈哈，我不要．", 0, 1);
        AddFame(3);
        exit();
::label1::
        LightScence();
        Talk("唉，你功夫還差的遠了，再去練練．", 64, 0);
        Talk("正好讓我考驗你武功進境如何?", 0, 0);
exit();