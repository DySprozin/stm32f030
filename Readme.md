Заметки

Как скопировать проект IAR (по мотивам https://stackoverflow.com/questions/22020845/renaming-in-iar-embedded-work-bench )

1) Скопировать и переименовать всю папку проекта (mypr -> mypr_new)

2) В папке mypr_new переименовать mypr.ewp -> mypr_new.ewp

3) В папке mypr открыть eww-файл

4) В меню: Project->Add Existing Project... - выбрать mypr_new.ewp

5) В воркспейсе слева выбрать вкладку mypr, затем ПКМ на проекте -> Remove

6) Save workspace as - в новой папке сохранить mypr_new.eww

7) Закрыть IAR

8) В новой папке mypr_new очистить подпапку Debug

9) Переименовать лишние файлы  (рядом с новым eww и ewp; если такой файл существует под новым именем, то старый удалить)

10) enjoy
