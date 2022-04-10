#!/bin/bash
echo "-------------------------------Меню---------------------------------------"
echo "Какое приложение вы хотите запустить?"
select proga in C wxmaxima LibreOffice_Calc
do
    case $proga in
        C)
            gcc -o main main.c
              ./main
              exit
              ;;
        wxmaxima)
            echo "Контрольный расчет с заданными значениями или Контрольный расчет со значениями из файла?"
            select maxima in raschet file
            do
                case $maxima in
                    raschet)
                          open /Users/user/projects/kyrsach/kyrsach.wxmx
                          ./start.sh
                          exit
                          ;;
                      file)
                        open /Users/user/projects/kyrsach/input.wxmx
                        ./start.sh
                        exit
                        ;;
                    *)
                        echo "Введите корректный вариант, $REPLY нет в списке"
                        ;;
              esac
              done
              ;;
          LibreOffice_Calc)
            echo "Это приложение пока дерьмовое и потом тоже"
            ./start.sh
            exit
            ;;
        *) 
              echo "Введите корректное приложение, $REPLY приложения нет в списке"
              ;;
  esac
done
