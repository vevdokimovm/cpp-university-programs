#lang racket

(define (halve x) (/ x 2))
(define (double x) (* 2 x))

(define (mul a b)
  (cond ((= b 0) 0)
        ((= (remainder b 2) 0) (mul (double a) (halve b)))
        (else (+ a (mul a (- b 1))))))


