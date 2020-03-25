#lang racket

(define (for-each procedure items)
  (cond ((null? items) (newline))
        (else (procedure (car items)) 
              (for-each procedure (cdr items)))))