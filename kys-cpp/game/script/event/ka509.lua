if InTeam(9) == true then goto label0 end;
    Talk("為甚麼你就甘心受我欺騙？因為你心中喜歡我，是不是？", 96, 0);
    exit();
::label0::
    Talk("為甚麼你就甘心受我欺騙？因為你心中喜歡我，是不是？", 96, 0);
    Talk("是便怎樣？", 0, 1);
    Talk("我很開心啊。", 18, 0);
    Talk("那鬼東西我們怎麼有，讓開．", 0, 0);
    Talk("施主若無屠獅大會的邀請函，就請回去吧。", 65, 1);
    Talk("老衲還道何方高人降臨，卻原來是魔教的大魔頭到了。老衲師兄弟三人坐關數十年，不但不理俗務，連本寺大事也素來不加聞問。不意今日得與魔教主相逢，實是生平之幸。", 65, 5);
    Talk("成昆，你居然沒死，看來這屠獅大會應該就是你搞的鬼。", 9, 1);
    Talk("三位少林僧不但武功卓絕，且是有德的高僧，只是墮入了圓真的奸計而不自覺。", 65, 1);
    Talk("張教主，老衲法名渡厄，這位白臉師弟，法名渡劫，這位黑臉師弟，法名渡難。陽頂天既死，我三人的深仇大怨，只好著落在現任教主身上。我們師侄空見、空性二人又都死在貴教手下。你既然來到此地，自是有恃無恐。數十年來恩恩怨怨，咱們武功上作一了斷便是。", 9, 1);
    Talk("是以二敵三，還要算上我一份。", 0, 0);
    if TryBattle(80) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("晚輩與貴派并無梁子，此來志在營救義父金毛獅王謝大俠。空見神僧雖為我義父失手誤傷，這中間頗有曲折。至於空性神僧之死，與敝派卻是全無瓜葛。三位不可但聽信圓真一面之辭，須得明辨是非才好。", 13, 0);
        Talk("你憑著甚麼，敢來替謝遜說情？難道我師兄弟三人，便殺你不得麼？", 9, 1);
        Talk("看來晚輩只好晚輩以一敵三。", 13, 0);
        Talk("無忌，還不住手，我生平最大的罪孽，乃是殺了空見大師。你義父若是落入旁人之手，自當奮戰到底，但今日是囚在少林寺中，我甘心受戮，抵了空見大師這條性命。", 9, 1);
        Talk("你失手傷了空見大師，那是成昆這惡賊奸計擺布，何況那天我們帶來的人頭是假的，成昆用計詐死，義父你全家血仇未報，豈能死在成昆手下？", 13, 0);
        Talk("我這一個多月來，每日聽著三位高僧誦經念佛，聽著山下寺中傳來的晨鐘暮鼓，回思往事，你義父手上染了這許多無辜之人的鮮血，實是百死難贖。唉，諸般惡因罪孽，我比成昆作得更多，我愿意在屠獅大會將以前欠下的債還完。", 0, 0);
        Talk("義父，你不肯走，我可要用強了。", 9, 1);
        ModifyEvent(-2, 7, 0, 0, -1, -1, 723, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 8, 0, 0, -1, -1, 723, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 9, 0, 0, -1, -1, 723, -1, -1, -1, -2, -2, -2);
exit();
