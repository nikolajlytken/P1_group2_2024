# How to rejseplanen API
### Train search

### Line info 

### Line match 

### Line search

## journeyDetail
Når du har fundet en liste af "JourneyDetail", kan du hente detaljer om en specifik rejse, via journeyDetail.

Den id der er vigtig er "ref".

## Plan for gathering info 



1: Hent "alle" tog navne via trainSearch. 
    -> Gem dem i en fil.
    
2: Fjern alle "duplikater" (Måske ikke til at starte med.)

3: Benyt lineMatch til at finde alle strækninger toget køre på. 
4: Skriv til fil, hvor hver linje er nyt tog. samtlige stationer toget køre igennem.
    -> Stationerne noteres med lon og lat. 
5: Komprimer det ned til at en fil, som er mulig at indlæse i c
    -> format: "StartSt, st, distance fra StartSt,"



