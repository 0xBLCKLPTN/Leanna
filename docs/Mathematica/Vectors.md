## Декартовы базисные векторы

Зачастую полезно определить три ортогональных единичных вектора ( то есть взаимно перпендикулярных вектора, каждый из которых имеет длину 1), соответствующих трем основным декартовым осям. Единичный вектор вдоль оси X обычно называется i, вдоль оси Y - j, а вдоль оси Z - k. Векторы i, j и k иногда называют декартовыми базисными векторами.

Любые точка или вектор могут быть выражены в виде суммы скаляров (действительных чисел), умноженных на единичные базисные векторы, например:

					$(5,3 -2)=5i+3j-2k$


## Векторные операции

Большинство математических операций, которые вы можете выполнить над скалярами, можно применить и к векторам. Есть и некоторые другие операции, которые применяются только к векторам.

### Умножение скаляр

Умножение вектора a на скаляр s выполняется умножением отдельных компонентов a на s:
					$sa=(sa_{x}, sa_{y}, sa_{z})$

Умножение скаляр дает эффект масштабирования длины вектора, оставляя его направление неизменным. Умножение на -1 изменяет направление вектора - начало ставится концом и наоборот.

Коэффициент масштабирования может быть различным для каждой оси. Это называется неоднородным масштабированием и может быть представлено как покомпонентное произведение вектора масштабирования s и рассматриваемого вектора, которое обозначим оператором $\otimes$. Этот особый вид произведения между двумя векторами известен как произведение Адамара. Оно редко используется в игровой индустрии - фактически неоднородное масштабирование является его единственным распространенным примером в играх:
					$s\otimes a = (s_{x}a_{x}, s_{y}a_{y},s_{z}a_{z})$

$$
aS=
\begin{bmatrix}
a_{x} & a_{y} & a_{z}
\end{bmatrix}
\begin{bmatrix}
s_{x} & 0 & 0 \\
0 & s_{y} & 0 \\
0 & 0 & s_{z}
\end{bmatrix}
=
\begin{bmatrix}
s_{x}a_{x} & s_{y}a_{y} & s_{z}a_{z}
\end{bmatrix}
$$


### Сложение и вычитание

Сложение векторов a и b определяются как вектор, компоненты которого являются суммами компонентов a и b.
$$
a+b = 
\begin{bmatrix}
\begin{pmatrix}
  a_{x} + b_{x}   
\end{pmatrix} 
\begin{pmatrix}
  a_{y} + b_{y}   
\end{pmatrix} 
\begin{pmatrix}
  a_{z} + b_{z}   
\end{pmatrix}
\end{bmatrix}
$$
Вычитание векторов a -b - это не что иное, как сложение векторов a и -b
$$
a-b = 
\begin{bmatrix}
\begin{pmatrix}
  a_{x} - b_{x}   
\end{pmatrix} 
\begin{pmatrix}
  a_{y} - b_{y}   
\end{pmatrix} 
\begin{pmatrix}
  a_{z} - b_{z}   
\end{pmatrix}
\end{bmatrix}
$$


Вообще векторные операции применяются в геймдеве ну почти везде. Возмем две сферы и хотим узнать пересекаются ли они. Учитывая что известны центральные точки сфер, $C_{1}$ и $C_{2}$, можем найти вектор направления между ними, просто определив их разность: $d=C_{2}-C_{1}$. Длина этого вектора $d=|d|$
 определяет как далеко друг от друга расположены центры сфер. Если это расстояние меньше суммы радиусов сфер, они пересекаются, в противном случае - нет.
					 $|d|\geq C_{1r}+C_{2r}$ - пересекаются.

На большинстве компьютеров, рассчитывать квадратные корни слишком затратно, поэтому разработчики игр всегда должны использовать квадратичную длину, когда это допустимо:
						$|d|^2=(a^2_{x}+a^2_{y}+a^2_{z})$
 
 
### Нормализация и единичные векторы

Единичный вектор - это вектор, длина которого равна 1. Единичные векторы очень полезны в трехмерной математике и при программировании игр, почему - увидим в дальнейшем.

Произвольный вектор v длиной $v=|v|$ можно преобразовать в единичный вектор $u$ который имеет то же направление, что и v, но единичную длину. Для этого просто умножим v на величину, обратную его длине:

								$u=\frac{v}{|v|}=\frac{1}{v}v$
Это называется нормализацией



### Скалярное произведение и проекция

Векторы можно умножать, но в отличии от умножение скаляров, существует множество видов умножения векторов. В программировании игр мы чаще всего работаем с двумя видами:
- со скалярным произведением
- векторным произведением

Скалярное произведение двух векторов дает скаляр, что определяется сложением произведений отдельных компонентов двух векторов:
						$a * b=a_{x}b_{x} +a_{y}b_{y} +a_{z}b_{z}=d$

Скалярное произведение можно записать также как произведение длин двух векторов и косинуса угла между ними:
						$a*b=|a| |b|\cos\theta$

Скалярное произведение является коммутативным (то есть порядок двух векторов может быть обратным) и дистрибутивным по сложению:
							$a*b=b*a$
							$a*(b+c)=a*b+a*c$

Скалярное произведение совмещается с умножением на скаляр следующим образом:
						$sa*b=a*sb=s(a*b)$
Проекция вектора. Если u - единичный вектор $(|u|=1)$, то скалярное произведение $a * b$ представляет длину проекции вектора а на бесконечную линию, определяемую направлением u. Эта концепция проекции одинаково хорошо работает как в 2D, так и в 3D и очень полезна для решения широкого спектра трехмерных задач.

Величина как скалярное произведение. Квадратичную величину вектора можно найти, взяв скалярное произведение этого вектора на самого себя. Его длина затем легко определяется взятием квадратного корня:
$|a|^2=a*a$
$|a|=\sqrt{ a*a }$

Тесты на основе скалярное произведения. Скалярные произведения отлично подходят для проверки коллиниарности и перпендикулярности двух векторов, а также их направлений: указывают ли они в примерно одинаковом или примерно противоположном направлениях. Для любых двух произвольных векторов a и b игровые разработчики часто используют следующие тесты
- коллинеарны. $a*b=|a| |b|=ab$, то есть угол между ними равен 0. Это скалярное произведение равно +1, когда a и b являются единичными векторами.
- перпендикулярны. $a*b=0$, то есть угол между ними составляет $90^{\circ}$
- сонаправлены. $a*b>0$, то есть уго между ними меньше $90^{\circ}$
- противоположно направлены. $a*b<0$, то есть угол между ними больше $90^{\circ}$

Другие применения скалярного произведения. Скалярное произведение может быть использовано для самых разнообразных задач в программировании игр. Допустим, мы хотим выяснить, находится-ли враг перед персонажем или позади него. Можем найти вектор из позиции игрока $P$ в позицию противника $E$ простым вычитанием векторов $(v=E-P)$. Предположим, у нас есть вектор $f$, указывающий в направлении, в котором смотрит игрок. C помощью скалярное произведения $d=v*f$ можно проверить, находится враг впереди или позади игрока: оно будет положительным, когда враг впереди, и отрицательным, когда позади. 