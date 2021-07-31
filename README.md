# Data-anonymization

## Scenario
As a Data Scientist in an industry that deals with private data The (legal, not moral) problem is that the data comes from many
countries, which don’t have the same legislation regarding private data, and
some users probably did not agree to give away their private data to other companies that work with us.
The aim of this project is to anonymize all these texts to
remove any personal data.

## Introduction
The goal of this tool is to detect Personal data in preprocessed texts (in CONLL format : https://stackoverflow.com/questions/27416164/what-is-conll-data-format)

## Sub-problem 1
The goal is to anonymize the ConLL2003 dataset, already pre-processed so that
each token (=sub-word) is represented as a numeric vector, one after another,
without the notion of sentences and then classify the 'PER' (personal) labels vs the rest of labels.

## Sub-problem 2
The goal is to build and compare classifiers for the original Named Entity Recognition (NER) problem in ConLL2003 i.e. not just for PERS vs rest. 

## Sub-problem 3 
The goal is to test our models on other datasets.

Please find further details in the "final-report.pdf" that I wrote.
