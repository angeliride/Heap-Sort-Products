Kolejną misją Grażyny, Janusza i Stacha jest złagodzenie skutków hiperinflacji, która dotknęła Polskę na przełomie lat 80. i 90. XX wieku.

W tamtym okresie cała gospodarka chwiała się w posadach. Szczególnie ciężko mieli przedsiębiorcy (nazywani wówczas prywaciarzami). Załoga Kronostatu musiała więc na chwilę odstąpić od prostowania linii czasu i zająć się księgowością – oczywiście w jej kreatywnej wersji.

Janusz i Stach mają za zadanie odnaleźć przedsiębiorców w tarapatach, co nie jest szczególnie trudnym wyzwaniem. Grażyna, jako mózg operacji i główna księgowa zespołu, musi zebrać od przedsiębiorców wykazy sprzedanych towarów i spróbować przyporządkować poszczególne produkty do najbardziej korzystnych kategorii podatkowych. Dzięki temu przedsiębiorcy zapłacą niższe podatki, co pomoże im uratować swoje biznesy.

Przykładowa tabela Pana Jasia, handlarza wihajstrami:

Cena	Procent podatku
1000	23
5000	30
200	5
300	18
2000	25

Grażyna doszła do wniosku, że odrobina kreatywności w tym przypadku nie zaszkodzi. Uważa ona, że najdroższy produkt, wyceniony na 5000 zł, nie powinien być w całości opodatkowany, ponieważ jego cena wynika z wartości wielu części składowych, a nie za wszystkie z nich należy naliczać podatek. Zdecydowała, że kwotę 4000 zł, która podlega opodatkowaniu, należy obciążyć najniższą stawką podatkową wynoszącą 5%. Z kolei "dla równowagi" najtańszy produkt powinien zostać opodatkowany najwyższą stawką – 30%. Grażyna jest przekonana, że Urząd Skarbowy nie powinien mieć zastrzeżeń. A jeśli jednak pojawią się wątpliwości, ma nietypowe rozwiązanie: należy wysłać urzędników na miesiąc do średniowiecza, co jej zdaniem skutecznie rozwiąże problem.
Pamiętaj, że jeżeli dana lista zawiera M produktów, to zawiera również M stawek podatkowych. Stawki te nie muszą być unikatowe. W obliczeniach Grażyna musi wykorzystać wszystkie M wartości.

Napisz program, który obliczy najniższą wartość podatku jaką mogą zapłacić przedsiębiorcy

Wejście
W pierwszej linii wejścia znajduje się liczba naturalna n - ilość przedsiębiorców, którym trzeba pomóc.
Następnie n-razy należy pobrać ze standardowego wejścia:
o - ilość operacji do wykonania dla danego przedsiębiorcy.
Kolejno pobieramy o linii w formacie:
a p t - dodaj produkt w cenie p zł, obłożony podatkiem t%
lub
p x - zmień cenę najdroższego produktu o x (jeśli ta operacja nie jest możliwa - nie rób nic).

1 ≤ n ≤ 30 000
1 ≤ o ≤ 100 000
1 ≤ p ≤ 100 000
1 ≤ t ≤ 100
-99 999 ≤ x ≤ 99 999

Wyjście
Na wyjściu powinniśmy otrzymać n linii z wyliczonym najniższym podatkiem dla każdego przedsiębiorcy wyrażony w groszach.
