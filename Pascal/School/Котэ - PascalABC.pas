uses graphABC;
begin
setwindowsize(600,500);
setbrushcolor(clGray);
Ellipse(100,430,500,130);
setbrushcolor(clNavy);
 
Ellipse(250,260,220,310);
Ellipse(350,260,380,310);
setbrushcolor(clblack);
Ellipse(270,330,330,370);
line(300,370,300,400);
Arc(300,280,120,220,-40);
 
line(120,240,150,40);
line(150,40,280,150);
line(280,150,120,240);
line(320,150,480,240);
line(480,240,450,40);
line(450,40,320,150);
floodfill(200,100,clGray);
floodfill(400,100,clGray);
line(50,350,200,350);
line(30,340,190,340);
line(10,330,180,330);
 
line(410,330,570,330);
line(400,340,560,340);
line(390,350,550,350);
 
line(250,240,220,150);
line(240,240,180,80);
line(230,240,180,150);
 
line(350,240,380,150);
line(360,240,430,80);
line(370,240,430,150);
 
end.