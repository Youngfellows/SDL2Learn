Talk("對不起，這位兄弟，都是我這個不幸之人的關系連累到你，我要去救水笙姑娘了。", 37, 0);
if AskJoin () == true then goto label0 end;
    Talk("水姑娘雖然誤會我一陣子，但我本來就不是啥淫僧，相處久了自然也就了解我的為人了，只是血刀老祖讓在旁時，我還是叫他繼續像以前一前辱罵我，才不會讓血刀老祖起疑", 0, 0);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 37, 0);
        exit();
::label1::
        Talk("裘爺稱贊我都沒在怕，你要不要和我一起走，英雄救美老子最愛干，咱就殺上血刀門，操一操那個血刀老祖．", 0, 1);
        Talk("好吧！如果你不怕被我的不幸連累的話", 37, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(37);
exit();
