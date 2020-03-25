program test;

var
otv, kol: real;

begin
kol := 0;
writeln('Как правильно пишется слово.');
writeln('1)изалированный');
writeln('2)изолированный.');
writeln('3)изолированый');
writeln('4)изалированый.');
writeln('');
readln(otv);
if otv = 2 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('Как зовут лучшего детектива во вселенной DC?');
writeln('1)SuperMan.');
writeln('2)Joker.');
writeln('3)Batman.');
writeln('4)Шерлок Холмс.');
writeln('');
readln(otv);

if otv = 3 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('Сколько будет 2+2*2?');
writeln('1)8.');
writeln('2)6.');
writeln('3)10.');
writeln('4)4.');
writeln('');
readln(otv);
if otv = 2 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('Остроумный,бессмертный наёмник?');
writeln('1)Фея Винкс.');
writeln('2)Человек-паук.');
writeln('3)Дедстроук.');
writeln('4)Дедпул.?');
writeln('');
readln(otv);
if otv = 4 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('');
writeln('Настоящее имя флэша?');
writeln('1)Гавриил.');
writeln('2)Акакий.');
writeln('3)Вася.');
writeln('4)Барри.');
writeln('');
readln(otv);
if otv = 4 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('Имя главного героя сериала Волчонок?');
writeln('1)Стайлз.');
writeln('2)Скотт.');
writeln('3)Дин.');
writeln('4)Дэймон.');
writeln('');
readln(otv);
if otv = 2 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('Средний тайминг рошана?');
writeln('"?');
writeln('1)10 минут. ');
writeln('2)8 минут.');
writeln('3)20 минут.');
writeln('4)12 минут.');
writeln('');
readln(otv);
if otv = 1 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('Полночь-это...');
writeln('1)24:00.');
writeln('2)06:00.');
writeln('3)12:00.');
writeln('4)8:00.');
writeln('');
readln(otv);
if otv = 1 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln(''); 
writeln('Имя Бэтмена.') ;
writeln('1)Гарри.');
writeln('2)Александр.');
writeln('3)Брюс.');
writeln('4)Люцифер.');
writeln('');
readln(otv);
if otv = 3 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
writeln('');
writeln('Самый главный враг Бэтмена');
writeln('1)Пингвин.');
writeln('2)Джокер.');
writeln('3)Комиссар Гордон.');
writeln('4)Крок.');
writeln('');
readln(otv);
if otv = 2 then
begin
writeln('правильно!');
kol := kol + 1;
end
else
begin
writeln('неправильно.');
end;
writeln('');
if (kol >= 0) and (kol < 3) then
writeln('Плохо');
if (kol >= 3) and (kol < 5) then
writeln('Нормально');
if (kol >= 5) and (kol < 7) then
writeln('Хорошо.');
if (kol >= 7) and (kol < 10) then
writeln('Отлично.');
if kol = 10 then
writeln('Ты человек?');
writeln(kol, ' правильных ответов')
end.