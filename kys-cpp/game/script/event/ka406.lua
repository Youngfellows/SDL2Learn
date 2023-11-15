Talk("來來來，來跟老頑童來玩兩招．", 64, 0);
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
        exit();
::label1::
        LightScence();
        Talk("唉，你功夫還差的遠了，再去練練．", 64, 0);
exit();
