# centre_de_la_france
L'affichage par gnuplot est plus complexe cette fois, mais pas impossible. Dans gnuplot, taper :


  a    = .05                  ; # Cette variable contrôle la taille des flèches sur la figure
  file = 'testPotentiel1.dat' ; # nom du fichier à dessiner
  z    = 5                    ; # altitude du plan de dessin
  set size square ; unset key ;
  p [-1:30][-1:30] file u ($3 == z ? $1 :1/0):2:(a*$4):(a*$5) every 7 w vectors head filled


Après, pour changer de dessin il suffit par exemple de faire :


  z  = 15 ; rep

ou encore :


  file = 'testPotentiel2.dat'
  z = 5
  rep
  
    a    = .01                       ; # Cette variable contrôle la taille des flèches sur la figure
  file = 'testPotentiel2-lapl.dat' ; # nom du fichier à dessiner
  z    = 8                         ; # altitude du plan de dessin
  set size square ; unset key ;
  p [-1:30][-1:30] file u ($3 == z ? $1 :1/0):2:(a*$4):(a*$5) w vectors head filled
