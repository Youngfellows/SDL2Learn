Talk("小子，你怎麼老是跑來靈蛇島，存心擾我老人家清靜是不？", 15, 0);
Talk("只怕您不是普通的老太婆，而是明教的四大護法之首，紫衫龍王．", 0, 1);
Talk("你這小子倒也厲害，居然知道我老太婆的真實身份．你說，這次來是做什麼？", 15, 0);
Talk("晚輩是替明教捎個口信，希望龍王能回光明頂去．", 0, 1);
Talk("要我回去做什麼，看他們在那里爭吵誰要當教主嗎？老太婆我倒寧愿留在這清靜清靜．", 15, 0);
Talk("龍王，你還有所不知，陽教主生前留下一封遺書，要謝護法暫代副教主之位．事情的經過是這樣的．．．", 0, 1);
Talk("那更好了，有謝三哥在，教中的一切事務，我就放心了．而我，就更可以在這休養了．", 15, 0);
Talk("＜看來得激她一下 ＞我說明教這”光明圣火陣”有多厲害嘛？我倒也不信．明教被六大派圍攻，還不是靠我去幫他們解圍．我看是謝護法不想給我這”倚天屠龍記”一書，才故意編了這麼一個難題．", 0, 1);
Talk("你說什麼？你是說我明教都沒人了，一切都要靠你這娃兒幫忙？", 15, 0);
Talk("我是沒這麼說，但事實是如此．", 0, 1);
Talk("小娃兒，不要以為運氣好打贏了幾場，就神氣起來了．要知一山還有一山高，我明教這”光明圣火陣”從創教至今，還沒人能破過．", 15, 0);
Talk("我就不信有什麼是破不了的．", 0, 1);
Talk("好大的口氣，我就讓你知道”光明圣火陣”的厲害，有種就上我光明頂來．", 15, 0);
ModifyEvent(11, 90, 1, 1, 111, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(11, 91, 1, 1, 112, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(11, 92, 1, 1, 113, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(11, 93, 1, 1, 114, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(11, 94, 1, 1, 115, -1, -1, -2, -2, -2, -2, -2, -2);
ModifyEvent(11, 101, 1, 1, 116, -1, -1, 5288, 5288, 5288, -2, -2, -2);
ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
Talk("黛綺絲，你還想往哪里逃，今日就要帶你回波斯總教。", 38, 1);
Talk("不好，是波斯總教的風云三使。", 15, 0);
Talk("龍王你先走，這里交給我。", 0, 1);
if TryBattle(141) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    if InTeam(114) == false then goto label1 end;
        AddItem(190, 1);
        Talk("黛綺絲，你還要戴著這個假面具嗎?", 0, 0);
        Talk("水姑娘，要不要一起走，可以跟你的狄大哥一起闖蕩江湖歐。", 32, 0);
        Talk("．．．．．．", 156, 0);
        Talk("公子，你能帶小昭一起去嗎?拜托。", 0, 0);
        Talk("帶你去沒什麼問題，不過你干麻這麼堅持。", 38, 0);
        Talk("<干!我有沒有看錯，眼前的美女居然是那個老太婆>", 156, 0);
        Talk("．．．．．．", 145, 0);
        Talk("你們武器都被我奪下了，還不住手。", 156, 0);
        Talk("等等，小昭你過來。", 56, 0);
        Talk("江南七怪一言九鼎，豈能言而無信。", 145, 0);
        Talk("三位使者千里迢迢來到中原，無非是想要我回去接波斯總壇的教主，但我已非處女，無法勝任，但我有一個女兒，你們可以帶她回去交差。", 156, 0);
        if InTeam(9) == true then goto label2 end;
            Talk("小昭．．．．", 0, 0);
            LeaveTeam(114);
            ModifyEvent(11, 101, 1, 1, 1199, -1, -1, 5288, 5288, 5288, -2, -2, -2);
            exit();
::label2::
            Talk("歐，就是這個女孩嗎?你愿意做我們波斯明教的教主么？", 9, 0);
            Talk("如果我不做，你們定會為難母親，我不答應也不行。", 145, 0);
            LeaveTeam(114);
            ModifyEvent(33, 21, 0, -2, -2, -2, 284, -2, -2, -2, -2, -2, -2);
            exit();
::label1::
            Talk("這三個家伙還真難纏，武功又稀奇古怪。咦，他們好像掉了東西。", 0, 0);
            AddItem(190, 1);
            Talk("哈哈，原來是明教圣火令。", 0, 1);
exit();
