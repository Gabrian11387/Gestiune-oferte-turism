# Gestiune oferte turism

Această aplicație permite gestiunea ofertelor de la o agentie de turism. Fiecare ofertă are un anumit tip (munte, mare, city break),o destinație, o dată de plecare și un preț.
Aplicatia permite:
 - Adaugarea de noi oferte 
 - Actualizarea unei oferte existene
 - Stergerea unei oferte
 - Vizualizare oferete ordonat dupa pret (crescator saudescrescator)
 - Vizualizare oferte filtrate după un criteriu (destinația lor)

 Aplicatia a fost realizată 100% în C și are majoritatea variabilelor alocate dinamic, prin urmare pointerii ca tip de dată au fost esențiali în realizarea acesteia. Ca și paradigmă de programare, întâlnim programarea procedurală.

 Aplicația este structurată pe 3 nivele: ui(main), service(business) și repository(storage), fiecare nivel apelând funcții din celălalt nivel inferior. În plus, fiecare fișier C are asociat un header pentru a se putea realiza legătura între fișiere, întrucât aplicația șă funcționeze ca un tot unitar. 

 Aplicația rulează în consolă unde se prezintă un meniu și opțiunile aferente fiecărei funcționalități. Se primesc date de la utilizator, care mai apoi sunt trecute printr-un validator, iar dacă nu reușesc să treacă de acesta, utilizatorul va primi un mesaj de informare. Odată trecute de validator, datele ajung în service, iar mai apoi în repo, de unde vor fi stocate în lista finală de oferte care există pe tot parcursul rulării aplicație și este ștearsă odată cu oprirea rulării acesteia. 
