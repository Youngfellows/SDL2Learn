if isUsingItem(137) == true then goto label0 end;
    if InTeam(2) == false then goto label1 end;
        Talk("苗大俠，我這就幫你敷上解藥．", 2, 1);
        DarkScence();
        ModifyEvent(-2, -2, -2, -2, 33, -1, -1, 5216, 5216, 5216, -2, -2, -2);
        ModifyEvent(-2, 9, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Talk("苗大俠，你覺得怎麼樣．", 0, 1);
        Talk("嗯！我覺得好多了．這柄寶刀請收下。少俠一路辛苦了，苗某不勝感激，若苗家有任何你需要的東西，請盡管拿取．這毒手藥王也真是厲害，用毒至深，想不到醫術也是一流．", 3, 0);
        AddItem(116, 1);
        Talk("藥王他老人家已過世了，這位姑娘是他徒弟．", 0, 1);
        Talk("多謝！當年我因為一件事曾與藥王有過沖突，所以當我聽說要去求毒手藥王時，我就勸你不要去．", 3, 0);
        Talk("是什麼事？", 0, 1);
        Talk("這一件事我到今日還是不能明白．十八年前，我誤傷了一位好友，只因兵刃上喂有劇毒，見血封喉，竟爾無法挽救．我想這毒藥如此厲害，多半與毒手藥王有關，因此去向他詢問．結果他一口否認，說他毫不知情，想我一來不會說話，二來心情甚惡，就打了起來", 3, 0);
        Talk("如此說來，這位好朋友是你親手殺死的了？", 0, 1);
        Talk("是的．", 3, 0);
        Talk("這好朋友姓啥叫什麼？", 0, 1);
        Talk("遼東大俠胡一刀．", 3, 0);
        if InTeam(1) == false then goto label2 end;
            Talk("當真是你殺了我父親．", 1, 1);
            Talk("你是胡一刀的兒子！好，快來將我殺了，替你爹報仇．", 3, 0);
            Talk("且慢．這中間有很大的誤會", 0, 1);
            Talk("有什麼誤會，他都承認了．", 1, 1);
            Talk("你聽我說，當年在苗大俠劍上偷偷喂毒的是名叫閻基的人．他因為知道苗，胡二人身上有兩本極重要的書，所以在兩人比武時偷偷喂上劇毒，想讓二人兩敗俱傷，他好坐收漁翁之利．只是，當初你二人為何比試，才讓閻基這小人從中搞鬼？", 0, 1);
            Talk("唉！當年我二人都因受過”金先生”的恩惠，所以當他的書籍被人偷出，我二人都想把書找齊送回去．．．．當時，我二人各找到一本，雙方都想把對方的書奪來，以便日後送回去，所以才相約比試．其實，只要好好講，或許我們可以一起去找尋這些書，但可能是聽雙方名聲太大，本就想互相較量一下，看看是他的胡家刀法厲害，還是我苗家劍法強．", 3, 0);
            Talk("這真是一場誤會．一切都是閻基那卑鄙小人所引起的，所幸這個小人已無法再作惡了．", 0, 1);
            Talk("照你這麼說，是我胡家刀法比不上你苗家劍法，所以死的才是我父親．", 1, 1);
            Talk("其實我心中有個遺憾，當年我砍到令尊手臂時，同時我也被令尊的後著踢倒在地，只因我劍上被喂上劇毒，令尊才會毒發死亡．所以到底是何者功夫高明，一直沒有答案．今天我看見你這麼大了，我很高興．但我更希望你能學好胡家刀法，把我打敗，讓胡家刀法發揚光大，那我對你爹也有個交待．屆時這位小兄弟想要的”飛狐外傳”一書也將一并送上．等你練好了胡家刀法，可隨時來找我．", 3, 0);
            exit();
::label2::
            Talk("苗大俠．這中間有很大的誤會．", 0, 1);
            Talk("有什麼誤會？", 3, 0);
            Talk("你聽我說，當年在苗大俠劍上偷偷喂毒的是名叫閻基的人．他因為知道苗，胡二人身上有兩本極重要的書，所以在兩人比武時偷偷喂上劇毒，想讓二人兩敗俱傷，他好坐收漁翁之利．只是，當初你二人為何比試，才讓閻基這小人從中搞鬼？", 0, 1);
            Talk("唉！當年我二人都因受過”金先生”的恩惠，所以當他的書籍被人偷出，我二人都想把書找齊送回去．．．．當時，我二人各找到一本，雙方都想把對方的書奪來，以便日後送回去，所以才相約比試．其實，只要好好講，或許我們可以一起去找尋這些書，但可能是聽雙方名聲太大，本就想互相較量一下，看看是他的胡家刀法厲害，還是我苗家劍法強．", 3, 0);
            Talk("這真是一場誤會．一切都是閻基那卑鄙小人所引起的，所幸這個小人已無法再作惡了，我會將這事轉告給胡大俠的兒子知道．", 0, 1);
            Talk("你知道他兒子的下落，快帶他來見我．", 3, 0);
            Talk("只怕他一看到你就想拼命．", 0, 1);
            Talk("其實我心中有個遺憾，當年我砍到胡兄手臂時，我同時也被胡兄的後著踢倒在地，只因我劍上被喂上劇毒，胡兄才會毒發死亡．所以到底是何者的功夫高明，一直沒有答案．今天我知道胡家有後，我很高興．但我更希望他能學好胡家刀法，把我打敗，讓胡家刀法發揚光大，那我對他爹也有個交待．屆時你想要的”飛狐外傳”一書也將送上．麻煩你轉告他，等他準備好了，可隨時來找我．", 3, 0);
exit();
::label1::
            exit();
::label0::
            AddMorality(3);
            if CheckEventID(10, -1) == true then goto label3 end;
                ModifyEvent(-2, 10, -2, -2, 867, -1, -1, -2, -2, -2, -2, -2, -2);
::label3::
                AddItemWithoutHint(137, -1);
                Talk("苗大俠，我這就幫你敷上解藥．", 0, 1);
                DarkScence();
                ModifyEvent(-2, -2, -2, -2, 33, -1, -1, 5216, 5216, 5216, -2, -2, -2);
                ModifyEvent(-2, 9, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
                LightScence();
                Talk("苗大俠，你覺得怎麼樣．", 0, 1);
                Talk("嗯！我覺得好多了．這柄寶刀請收下。少俠一路辛苦了，苗某不勝感激，若苗家有任何你需要的東西，請盡管拿取．這毒手藥王也真是厲害，用毒至深，想不到醫術也是一流．", 3, 0);
                AddItem(116, 1);
                Talk("藥王他老人家已過世了，這解藥是他徒弟調制的．", 0, 1);
                Talk("難怪，當年我因為一件事曾與藥王有過沖突，所以當我聽說要去求毒手藥王時，我就勸你不要去．", 3, 0);
                Talk("是什麼事？", 0, 1);
                Talk("這一件事我到今日還是不能明白．十八年前，我誤傷了一位好友，只因兵刃上喂有劇毒，見血封喉，竟爾無法挽救．我想這毒藥如此厲害，多半與毒手藥王有關，因此去向他詢問．結果他一口否認，說他毫不知情，想我一來不會說話，二來心情甚惡，就打了起來", 3, 0);
                Talk("如此說來，這位好朋友是你親手殺死的了？", 0, 1);
                Talk("是的．", 3, 0);
                Talk("這好朋友姓啥叫什麼？", 0, 1);
                Talk("遼東大俠胡一刀．", 3, 0);
                if InTeam(1) == false then goto label4 end;
                    Talk("當真是你殺了我父親．", 1, 1);
                    Talk("你是胡一刀的兒子！好，快來將我殺了，替你爹報仇．", 3, 0);
                    Talk("且慢．這中間有很大的誤會", 0, 1);
                    Talk("有什麼誤會，他都承認了．", 1, 1);
                    Talk("你聽我說，當年在苗大俠劍上偷偷喂毒的是名叫閻基的人．他因為知道苗，胡二人身上有兩本極重要的書，所以在兩人比武時偷偷喂上劇毒，想讓二人兩敗俱傷，他好坐收漁翁之利．只是，當初你二人為何比試，才讓閻基這小人從中搞鬼？", 0, 1);
                    Talk("唉！當年我二人都因受過”金先生”的恩惠，所以當他的書籍被人偷出，我二人都想把書找齊送回去．．．．當時，我二人各找到一本，雙方都想把對方的書奪來，以便日後送回去，所以才相約比試．其實，只要好好講，或許我們可以一起去找尋這些書，但可能是聽雙方名聲太大，本就想互相較量一下，看看是他的胡家刀法厲害，還是我苗家劍法強．", 3, 0);
                    Talk("這真是一場誤會．一切都是閻基那卑鄙小人所引起的，所幸這個小人已無法再作惡了．", 0, 1);
                    Talk("照你這麼說，是我胡家刀法比不上你苗家劍法，所以死的才是我父親．", 1, 1);
                    Talk("其實我心中有個遺憾，當年我砍到令尊手臂時，同時我也被令尊的後著踢倒在地，只因我劍上被喂上劇毒，令尊才會毒發死亡．所以到底是何者功夫高明，一直沒有答案．今天我看見你這麼大了，我很高興．但我更希望你能學好胡家刀法，把我打敗，讓胡家刀法發揚光大，那我對你爹也有個交待．屆時這位小兄弟想要的”飛狐外傳”一書也將一并送上．等你練好了胡家刀法，可隨時來找我．", 3, 0);
exit();
::label4::
                    Talk("苗大俠．這中間有很大的誤會．", 0, 1);
                    Talk("有什麼誤會？", 3, 0);
                    Talk("你聽我說，當年在苗大俠劍上偷偷喂毒的是名叫閻基的人．他因為知道苗，胡二人身上有兩本極重要的書，所以在兩人比武時偷偷喂上劇毒，想讓二人兩敗俱傷，他好坐收漁翁之利．只是，當初你二人為何比試，才讓閻基這小人從中搞鬼？", 0, 1);
                    Talk("唉！當年我二人都因受過”金先生”的恩惠，所以當他的書籍被人偷出，我二人都想把書找齊送回去．．．．當時，我二人各找到一本，雙方都想把對方的書奪來，以便日後送回去，所以才相約比試．其實，只要好好講，或許我們可以一起去找尋這些書，但可能是聽雙方名聲太大，本就想互相較量一下，看看是他的胡家刀法厲害，還是我苗家劍法強．", 3, 0);
                    Talk("這真是一場誤會．一切都是閻基那卑鄙小人所引起的，所幸這個小人已無法再作惡了，我會將這事轉告給胡大俠的兒子知道．", 0, 1);
                    Talk("你知道他兒子的下落，快帶他來見我．", 3, 0);
                    Talk("只怕他一看到你就想拼命．", 0, 1);
                    Talk("其實我心中有個遺憾，當年我砍到胡兄手臂時，我同時也被胡兄的後著踢倒在地，只因我劍上被喂上劇毒，胡兄才會毒發死亡．所以到底是何者的功夫高明，一直沒有答案．今天我知道胡家有後，我很高興．但我更希望他能學好胡家刀法，把我打敗，讓胡家刀法發揚光大，那我對他爹也有個交待．屆時你想要的”飛狐外傳”一書也將送上．麻煩你轉告他，等他準備好了，可隨時來找我．", 3, 0);
exit();