ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 3500, 3500, 3500, -2, -2, -2);
AddItem(157, 1);
if InTeam(72) == true then goto label0 end;
    exit();
::label0::
    DarkScence();
    LightScence();
    Talk("鴛鴦刀山洞?那里能解開鴛鴦刀的秘密?怎麼我沒聽說過，可不可以帶我一起去那鴛鴦刀山洞看看．", 202, 0);
    Talk("作夢，剛才還大呼小叫罵我無恥，休想我會帶你去．", 0, 5);
    Talk("看你一附不帶我去，就要自殺的樣子，算我怕了你．", 201, 1);
    Talk("看來鴛鴦刀天下無敵的秘密就在你剛才拿到的那本書里", 0, 5);
    Talk("又亂入，煩死人，怎麼每次都搞這一套．", 202, 0);
    Talk("爹爹!", 0, 5);
    if TryBattle(266) == true then goto label1 end;
::label1::
        LightScence();
        Talk("你是蕭姑娘的老爹?", 0, 5);
        Talk("正是，老夫蕭半和，少年，交出那本書吧，老夫會留你一個全屍．", 202, 0);
        Talk("怕你不成，動手吧!", 0, 5);
        Talk("干，你他媽的怎麼這麼強，居然從我手中搶走我的書．", 202, 0);
        Talk("老夫六歲起就凈身入宮，有緣從一位老太監身上習得葵花寶典．", 201, 1);
        Talk("．．．．．．", 202, 0);
        Talk("老夫六歲起就凈身入宮，有緣從一位老太監身上習得葵花寶典．", 201, 1);
        Talk("原來又是一個死太監，不對啊 你是太監怎麼會有女兒．", 202, 0);
        Talk("別吵．．．他媽的這本破書耍人嗎?操，這本書你要就拿去，浪費老子的時間，告辭．", 201, 1);
        LeaveTeam(72);
        Talk("太監就不能有子女?這女兒是我領養回來的，不多說，我就看看這鴛鴦刀的第一頁．", 0, 5);
        Talk("爹，你快說，這不是真的．", 0, 0);
        Talk("我看一下鴛鴦刀得第一頁，怎麼那死太監看完著麼生氣?", 0, 0);
exit();