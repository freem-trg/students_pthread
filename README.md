students_pthread
================
После экзамена 12 студентов решили отметить его окнчание в столовой. Однако оказалось, что другие студенты  решили поступить так же, и в столовой остался всего 1 свободный столик на 4 человека. 4 человека пошли есть, а остальные 8 заснули в коридоре. Каждый поевший, выходя из столовой, будит одного спящего, и тот идет обедать. Ест студент случайное время.
Смоделировать эту ситуацию при помощи программы в С++11. Каждый студент представлен потоком. Запускаются 12 потоков, 4 случайных потока садятся за стол, остальные засыпают до получения сигнала. Поев некоторое время (приостановить поток на случайное количество времени), поток посылает сигнал любому из спящих потоков и завершает свою работу. Для синхронизации использовать мьютекс и условную переменную.