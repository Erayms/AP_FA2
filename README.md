# Warehouse

## About
Dit is mijn herkansing en heb ik de feedback die ik heb gekregen verwerkt. 

Feedback: Niet getest op de daadwerkelijke inhoud van de pallets na het uitvoeren van pickItems, en er wordt geen rekening gehouden met dat de inhoud van de pallets anders zou moeten zijn na elke call.

Ik heb ervoor gezorgd dat er bij elke pickItems call word gekeken naar de inhoud van de pallets om in te kunnen zien of de aantallen daadwerkelijk veranderen na het uitvoeren van pickItems. Dit gebeurd nu wel zoals te zien is tijdens het runnen van de testWarehouse.exe. Op deze manier kan je inzien of er na elke call daadwerkelijk verandering is in de aantallen, na het uitvoeren van pickItems en of de inhoud veranderd is na een call.

Feedback: In de functie pickItems gaat het dus ook op twee manieren fout.
Ten eerste wordt er door kopieën van shelves/pallets geloopt, ipv references naar die shelves/pallets, na het doorlopen van de functie zijn er dus geen items uit de daadwerkelijke pallets in de warehouse gehaald. 

Dit is nu helemaal opgelost door references te gebruiken word er nu wel daadwerkelijk uit de pallets items gehaald wat voorheen dus niet gebeurde. Dit is nu ook terug te zien in de tests. De tests die ik hier voor heb geschreven is na het legen van Books op een shelf, proberen om 10 Books te picken. Dit faalt nu wat klopt omdat ze er niet meer zijn.

Feedback: Daarnaast wordt er vóór het picken van items niet gekeken of er wel genoeg items zijn om mee te beginnen; nu worden er alsnog items gepickt ookal zijn er niet genoeg. 
Er zit nu in mijn pickItems functie een if statement waar word gekeken of er wel genoeg items zijn, is dit niet zo krijg je een print statement terug te zien dat er niet genoeg items zijn. Dit is ook weer terug te zien in de tests die ik heb geschreven.

Feedback: Afgezien daarvan zijn de imports best een rommeltje, het was even puzzelen om je code te kunnen compileren.
Als het goed is werkt mijn Makefile nu gewoon en is het simpel te compileren door gewoon make uit te voeren in de terminal. Ik maak ook geen gebruik meer van absolute imports.

Feedback: Bovendien werkt rearrangeShelf niet en is deze onlogisch opgeschreven. 
rearrangeShelf is aangepast en werkt nu ook in alle omstandigheden.

Feedback: Je hebt geen gebruik gemaakt van overerving.
Ik heb nu de class IContainer aangemaakt. Shelf en Pallet erven de IContainer class nu en de isEmpty en isFull functies.

## How to run
1. Zorg ervoor dat je in de directory van warehouse zit
2. Run make
3. Nu is het mogelijk om de testWarehouse.exe en main.exe te runnen.