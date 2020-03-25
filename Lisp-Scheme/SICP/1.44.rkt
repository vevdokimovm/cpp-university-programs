#lang racket

(define (repeated f n)
  (if (> n 1)
      (lambda (x) ((compose (repeated f (- n 1)) f) x))
      f))

(define (compose f g)
  (lambda (x) (f (g x))))

(define (average x y z) (/ (+ x y z) 3.0))

(define (smooth f dx)
  (lambda (x) (average (f (- x dx)) (f x) (f (+ x dx)))))

;(define dx 0.00001)

(define (square x) (* x x))

(define (n-smooth f dx n)
  (repeated (smooth f dx) n))

(define (smooth-n f dx n)
  ((repeated (lambda (g) (smooth g dx)) n) f))