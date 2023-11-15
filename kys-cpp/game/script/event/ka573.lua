if isUsingItem(131) == true then goto label0 end;
    exit();
::label0::
    AddMorality(2);
    AddItemWithoutHint(131, -1);
    Talk("哈哈，有了大燕皇帝世系譜表及傳國玉璽，我就可號召大燕後代，實行復國計劃．", 139, 0);
    Talk("慕容公子此次不會再失信了吧．", 0, 1);
    Talk("我慕容復何時曾失信過人．", 139, 0);
    Talk("＜貴人多忘事＞", 0, 1);
    Talk("”天龍八部”一書的下落是在．．．．．", 139, 0);
    Talk("在那里？", 0, 1);
    Talk("在喬峰的手里．", 139, 0);
    Talk("你是說丐幫幫主喬峰．", 0, 1);
    Talk("正是．", 139, 0);
    Talk("你該不會是隨便說說的吧．人家稱你們為”南慕容，北喬峰”，你就說書在他那．", 0, 1);
    Talk("我表哥沒有說謊，此書的確是流落在他的手中．", 109, 0);
    Talk("王姑娘說的話就可以信了．好，我就上丐幫要書去了．", 0, 1);
    Talk("不對，不對，閣下應該先上少林才對．", 139, 0);
    Talk("此話怎講？", 0, 1);
    Talk("你想想看，你打得過那喬峰嗎？", 139, 0);
    Talk("打不過也得打，不然怎麼辦？", 0, 1);
    Talk("我有辦法讓喬峰乖乖的將書交出來．", 139, 0);
    Talk("他為什麼會乖乖交出來．", 0, 1);
    Talk("因為我知道他一個極大的秘密，一個足以讓他身敗名裂的秘密．", 139, 0);
    Talk("那為什麼要先到少林？", 0, 1);
    Talk("因為得先到少林寺拿一樣東西．", 139, 0);
    Talk("一樣東西？", 0, 1);
    Talk("是的，一樣能讓武林天翻地覆的東西．總之，你若和我一同前往，我可以讓你輕易獲得該書．否則，你自己一個人有自信打敗喬峰嗎？", 139, 0);
    Talk("你為什麼要幫我？", 0, 1);
    Talk("沒什麼，魚幫水，水幫魚．我慕容氏人丁單薄，勢力微弱，想要重建邦國，談何容易？唯一的機會便是天下大亂，武林動蕩不安．而你也可從中得到你要的東西．", 139, 0);
    Talk("表哥，你不要想復國想到瘋了，弄得天下大亂．", 109, 0);
    Talk("住嘴！你以為我這慕容復的”復”字是為何取的，我慕容家族世世代代奔波一生，所為何事？怎樣，你要不要和我合作？", 139, 0);
    ModifyEvent(-2, 5, -2, -2, 497, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, -2, -2, -2, 494, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 2, -2, -2, 495, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(51, 14, -2, -2, 527, 531, -1, -2, -2, -2, -2, -2, -2);
    if AskJoin () == true then goto label1 end;
        Talk("慕容公子的”好”意，在下心領了．在下對自己的武功還有一點自信，我寧愿光明正大的與喬大俠打斗，也不愿用卑鄙的方法去得到那本”天龍八部”．", 0, 1);
        Talk("你再考慮清楚．", 139, 0);
        exit();
::label1::
        Talk("好，我就和你上少林，揭發喬峰的秘密．", 0, 1);
        if TeamIsFull() == false then goto label2 end;
            Talk("你的隊伍已滿，我無法加入．", 139, 0);
            exit();
::label2::
            DarkScence();
            ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(-2, 2, -2, -2, 495, -1, -1, -2, -2, -2, -2, -2, -2);
            LightScence();
            Join(51);
exit();
