# Makefile for building LaTeX documents

# Variables
TEX = pdflatex
#BIBTEX = bibtex

# Main document name (without extension)
MAIN = hw12-Petersen

# Automatically generated dependencies
DEP = $(MAIN).aux #$(MAIN).bbl

# Default target
all: $(MAIN).pdf

# Rule to build PDF from TeX
$(MAIN).pdf: $(MAIN).tex $(DEP)
	$(TEX) $(MAIN).tex

# Rule to generate bibliography
#$(MAIN).bbl: $(MAIN).aux $(MAIN).bib
#	$(BIBTEX) $(MAIN)

# Rule to generate aux file
$(MAIN).aux: $(MAIN).tex
	$(TEX) $(MAIN).tex

# Clean up intermediate files
clean:
	rm -f $(MAIN).aux $(MAIN).log $(MAIN).bbl $(MAIN).blg $(MAIN).out $(MAIN).toc

# Full clean (including PDF output)
clean-all: clean
	rm -f $(MAIN).pdf

.PHONY: all clean clean-all

