#lang racket

(define (identity x) x)

(define (cube x) (* x x x))
 
(define (inc x) (+ x 1))

(define (accumulation combine null-value term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (combine result (term a)))))
  (iter a null-value))

(define (product term a next b)
  (accumulation * 1 term a next b))

(define (sum term a next b)
  (accumulation + 0 term a next b))

(define (factorial n)
  (product identity 1 inc n))

(define (sum-cubes a b)
  (sum cube a inc b))