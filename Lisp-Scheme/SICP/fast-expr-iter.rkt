#lang racket
(define (fast-expr-iter a b n)
  (cond ((= n 0) a)
        ((= (remainder n 2) 0) (fast-expr-iter a (* b b) (/ n 2)))
        (else fast-expr-iter (* a b) b (- n 1))))

(fast-expr-iter 1 2 7)