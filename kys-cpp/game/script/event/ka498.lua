Talk("小和尚，你一直看你的茶做啥．．．", 0, 1);
Talk("佛觀一滴精，八萬四千蟲", 49, 0);
Talk("干!我以為這個道理我懂!沒想到我遇到了知音人", 0, 1);
Talk("佛說每一滴精液中，有八萬四千條小蟲，所以千萬別打手槍．．．．", 49, 0);
Talk("真靠北．", 0, 1);
Talk("施主有所不知．我輩凡夫看來，精中自然無蟲，但我佛以天眼看精，卻看到精液中小蟲成千上萬．", 49, 0);
Talk("嘴炮打完了沒?", 0, 1);
Talk("看你面色蒼白，昨完不曉得殺了多少只小蟲．", 49, 0);
Talk("對了，你怎麼在這？你師父跟師兄弟呢?", 0, 1);
Talk("干，想到就氣．我跟師兄弟門走散了", 49, 0);
Talk("原來被拋棄了，你的目的地在哪?", 0, 1);
Talk("我師門的人可能到那擂鼓山去了．", 49, 0);
ModifyEvent(-2, -2, -2, -2, 499, -1, -1, -2, -2, -2, -2, -2, -2);
if AskJoin () == true then goto label0 end;
    Talk("掰，那改天我們再見．", 0, 1);
    exit();
::label0::
    Talk("既然如此，我就帶你去擂鼓山找你的師父師兄弟吧．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 49, 0);
        exit();
::label1::
        Talk("好啊．", 49, 0);
        DarkScence();
        ModifyEvent(-2, 2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 15, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(49);
        AddMorality(3);
exit();
