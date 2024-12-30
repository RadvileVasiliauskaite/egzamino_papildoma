<h1> Objektinio programavimo egzamino papildoma užduotis</h1>
<h> Pasikartojančių žodžių skaičiavimas ir URL radimas</h>

Programa leidžia pasirinkti vartotojui 3 pasirinkimus: 
 1.Rasti pasikartojančių žodžių skaičių(išvedama į failą žodžiai ir jų pasikartojimų skaičius). Ši funkcija atlieka žodžių skaičiavimą ir jų pasikartojimo sekimo analizę. Naudodama countWordsAndLines funkciją, ji analizuoja įvesties failą, suskaido tekstą į žodžius, suskaičiuoja jų pasikartojimus ir seka, kuriose eilutėse jie pasirodo. Pabaigoje, naudodama writeWordCounts funkciją, ji įrašoma žodžių ir jų pasikartojimų ataskaitą į failą
  2.Sukurti cross-reference tipo lentelę, kurioje nurodomas žodis ir eilutės kuriose pasikartojo žodis. Šis pasirinkimas sukuria žodžių ir jų pasikartojimo eilučių ataskaitą. Jei žodžių eilutės dar nebuvo analizuojamos, pirmiausia naudojama countWordsAndLines funkcija, kad būtų sukaupta reikiama informacija. Vėliau, writeCrossReference funkcija generuoja ir įrašo žodžių pasikartojimo eilučių lentelę į failą
 3.Rasti URL adresus tekste (atspausdinami ekrane). Šis pasirinkimas identifikuoja URL adresus tekste, naudodamas reguliarias išraiškas. findURLs funkcija analizuoja įvesties failą, ieškodama atitinkančių URL modelių, ir prideda juos į rinkinį urls. Vėliau, rastus URL adresus išveda ekrane, kad vartotojas galėtų juos peržiūrėti.
