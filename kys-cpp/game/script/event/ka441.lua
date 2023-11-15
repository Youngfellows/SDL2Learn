Talk("少俠近來如何？", 121, 0);
if AskJoin () == true then goto label0 end;
    Talk("一切還好，你們還好吧？", 0, 1);
    Talk("嗯．", 121, 0);
    Talk("你們倆真是令人羨慕的神仙俠侶．", 0, 1);
    exit();
::label0::
    Talk("近日旅途有些不順，此次前來是想請龍姑娘加入，助我一臂之力．", 0, 1);
    Talk("好啊，我夫婦倆受你這麼大的恩惠，理應幫忙你一些．", 121, 0);
    Talk("真是不好意思，打擾了你跟楊兄的清靜．", 0, 1);
    Talk("沒有關系，等解決了你的問題後，再回來古墓就好了．", 121, 0);
    Talk("謝謝你的幫忙．", 0, 1);
    DarkScence();
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 121, 0);
        exit();
::label1::
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(59);
exit();
