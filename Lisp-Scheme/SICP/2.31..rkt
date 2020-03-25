#lang racket

(define (tree-processing tree null-value combiner glue)
  (cond ((null? tree) null-value)
        ((not (pair? tree)) (combiner tree))
        (else (glue (tree-processing (car tree) null-value combiner glue)
                    (tree-processing (cdr tree) null-value combiner glue)))))

(define square (lambda (x) (* x x)))

(define (tree-map proc tree)
  (tree-processing tree null proc cons))

(define (square-tree tree)
  (tree-map square tree))

(define x (list 1
                (list 2 (list 3 4) 5)
                (list 6 7)))