if InTeam(36) == true then goto label0 end;
    Talk("哼！廢話少說，要殺要剮隨你．", 24, 0);
    exit();
::label0::
    Talk("余滄海，來受死吧，今天我要你青城派在武林中消失．", 36, 1);
    Talk("余觀主，聽說你得了《辟邪劍譜》，不知可否借駝子瞧一瞧？", 71, 1);
    Talk("來得正好。木駝子，害死我爹娘你也有份。你不是要見識我林家的辟邪劍法嘛，今天我就成全你。", 36, 0);
    Talk("平之，我幫你！", 126, 1);
    if TryBattle(51) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 3, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 4, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Talk("那也好！你安心養傷，盼你早來華山。", 86, 0);
        Talk("令狐兄弟，我們走吧!這次岳不群得到五岳劍派掌門之位，我總有一股說不出來的感覺。", 36, 0);
        Talk("平弟，恭喜你報了大仇。你眼睛怎樣了？", 126, 1);
        Talk("我的眼睛!!!!!!!!!!!", 36, 1);
        Talk("恒山派的金創藥好，弟子……弟子好了養傷，再來拜見師父師娘。", 71, 1);
        Talk("哈哈，本爺爺就算要死，也要你賠一雙招子。", 36, 1);
        Talk("師父，師父！師父死了，師父死了！", 126, 1);
        Talk("我報了仇啦，我報了仇啦！", 36, 0);
        Talk("可惡的東西，敢使計毒瞎老子的眼睛，去死去死去死。", 126, 1);
        Talk("平之，木高峰已經死了，你眼睛上那些毒水得洗一洗。", 36, 0);
        Talk("不要臉的賤貨滾開!", 126, 1);
        Talk("你……你……竟敢對我說這等話？", 36, 0);
        Talk("這姓余的矮子、姓木的駝子，他們想得我家的辟邪劍法，便出手硬奪，害死我父親母親，雖然兇狠毒辣，也不失為江湖上惡漢光明磊落的行逕，那像……那像……那像你的父親君子劍岳不群，卻以卑鄙奸猾的手段，來謀取我家的劍譜。", 126, 1);
        Talk("無恥賤人！你父女倆串謀好了，引我上鉤。華山派掌門的岳大小姐，下嫁我這窮途末路、無家可歸的小子，那為了什么？還不是為了我林家的辟邪劍譜。劍譜既已騙到了手，還要我姓林的干什么？", 0, 0);
        Talk("你少假惺惺了跟我稱兄道弟，你幫我也不過看中了我家的劍譜。既然我大仇得報，我也不想欠你人情，劍譜就給你瞧一瞧，告辭。", 36, 0);
        Talk("那……那有此事？", 126, 1);
        AddItem(78, 1);
        Talk("你……冤枉好人，我若有此意，教我……教我天誅地滅。", 0, 0);
        if InTeam(49) == false then goto label2 end;
            Talk("平之!平之!", 49, 0);
::label2::
            ModifyEvent(88, 0, 0, -2, -2, -2, 726, -2, -2, -2, -2, -2, -2);
            LeaveTeam(36);
            AddFame(3);
exit();