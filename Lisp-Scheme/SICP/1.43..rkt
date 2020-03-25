#lang racket

(define (square x) (* x x))

(define (repeated f n)
  (lambda (x) (repeat f n x)))

(define (repeat f n result)
  (if (= n 0)
      result
      (repeat f (- n 1) (f result))))

(define (compose f g)
  (lambda (x) (f (g x))))