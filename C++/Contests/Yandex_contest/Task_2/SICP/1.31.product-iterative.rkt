#lang racket

(define (inc x)
  (+ x 1))

(define (identity x) x)

(define (square x) (* x x))

(define (product term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (* result (term a)))))
  (iter a 1))

(define (factorial a)
  (product identity 1 inc a))

(define (pi-sum n)
  (* 4 (John-Wallis-method 3 n)))

(define (John-Wallis-method a b)
  (define (pi-term x)
    (/ (* 1.0 (- x 1) (+ x 1)) (square x)))
  (define (pi-next x)
    (+ x 2))
  (product pi-term a pi-next b))