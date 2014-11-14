#!/usr/bin/bash

rm *.{toc,out,aux,log}

for f in *.tex; do
  name=${f/.*}
  echo $name
  rm $name.{aux,log,out,toc,out.pyg}
  texify --pdf --engine=xetex --tex-option=--shell-escape --tex-option=-8bit --quiet $name.tex 
  rm $name.{aux,log,out,toc,out.pyg}
done

rm *.{toc,out,aux,log}
