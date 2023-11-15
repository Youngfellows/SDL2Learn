Talk("閣下也是來搶經書的嗎？", 68, 0);
if AskBattle() == true then goto label0 end;
    Talk("丘道長，你別誤會。我是聽說有人上全真教搗亂，若您不嫌棄我想來為您助拳的。", 0, 1);
    Talk("你可以嗎？", 129, 0);
    Talk("金輪法王、瀟湘子、尹克西、尼摩星，你們幾個小爺還沒放在心上。", 0, 1);
    if TryBattle(149) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("好家伙，這群惡賊還真不好對付。", 0, 0);
        Talk("今日之事，多謝少俠仗義出手。全真教深感大恩，無以回報。這柄佩劍是先師遺物，略表寸心。請少俠不要推辭。", 68, 1);
        Talk("謝謝道長．", 0, 1);
        AddItem(112, 1);
        AddMorality(5);
        AddFame(10);
        ModifyEvent(-2, -2, -2, -2, 458, -1, -1, -2, -2, -2, -2, -2, -2);
        exit();
::label0::
        Talk("前輩是丘掌門吧，我聽說先師王重陽武功天下第一，所以想看看他所創的全真教是否同他一樣厲害．", 0, 1);
        Talk("廢話少說，試試我們的天罡北斗陣！．", 68, 0);
        Talk("小兄弟，別怕！我們助你一臂之力。", 129, 1);
        if TryBattle(74) == true then goto label2 end;
            Dead();
            exit();
::label2::
            ModifyEvent(-2, -2, -2, -2, 459, -1, -1, -2, -2, -2, -2, -2, -2);
            LightScence();
            if HaveItemBool(54) == false then goto label3 end;
                Talk("不過可惜，家師的武學秘籍已被我毀了。雖說這是對師父大不敬，但總好過經書被你們這些無恥之徒奪去。", 68, 0);
                Talk("公布連城訣的秘密，我相信師父如果沒死的話一定會出現。", 0, 0);
                exit();
::label3::
                AddItem(54, 1);
                Talk("哈哈！有了這本秘籍，天下第一舍我取誰！", 0, 0);
                Talk("沒想到你為了奪經竟然勾結外族，簡直喪心病狂！", 68, 1);
                Talk("那又如何？自古成王敗寇。", 0, 0);
                Talk("這么說來，我們今天殺你也不算過分。", 57, 1);
                Talk("誰？", 0, 0);
                Talk("我。", 60, 1);
                Talk("還有老衲。", 65, 0);
                Talk("再加我老叫花子。", 69, 1);
                Talk("哈哈！天下五絕已到其四，我的面子可真不小了。可惜王重陽已死，不然……", 0, 0);
                Talk("不然如何？", 64, 1);
                Talk("老頑童，連你也來了。看來今日一戰難免，你們一起上吧！人生如此，夫復何求？", 0, 0);
                if TryBattle(75) == true then goto label4 end;
                    Dead();
                    exit();
::label4::
                    ModifyEvent(18, 2, 1, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
                    ModifyEvent(18, 3, 1, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
                    LightScence();
                    Talk("唉……難道世間真的再無人是我敵手了！", 0, 0);
                    AddMorality(-20);
                    AddFame(25);
exit();
