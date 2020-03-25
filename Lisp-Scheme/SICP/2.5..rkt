#lang racket

(define (square x) (* x x))

(define (exp b n)
  (power b n 1))

(define (power b n a)
  (cond ((= n 0) a)
        ((even? n) (power (square b) (/ n 2) a))
        (else (power b (- n 1) (* a b)))))

(define (cons a b)
  (* (exp 2 a) (exp 3 b)))
  
(define (first num counter)
  (if (= (remainder num 2) 1)
      counter
      (first (/ num 2) (+ counter 1))))

(define (car object)
  (first object 0))

(define (second num counter)
  (if (= (remainder num 3) 0)
      (second (/ num 3) (+ counter 1))
      counter))

(define (cdr object)
  (second object 0))