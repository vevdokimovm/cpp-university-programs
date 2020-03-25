#lang racket

(define (make-segment a b)
  (cons a b))

(define (start-segment AB)
  (car AB))

(define (end-segment AB)
  (cdr AB))

(define (make-point x y)
  (cons x y))

(define (x-point A)
  (car A))

(define (y-point A)
  (cdr A))

(define (average x y)
  (/ (+ x y) 2.0))

(define (midpoint-segment AB)
  (make-point (average (x-point (start-segment AB)) (x-point (end-segment AB)))
              (average (y-point (start-segment AB)) (y-point (end-segment AB)))))

(define (print-point A)
  (newline)
  (display "(")
  (display (x-point A))
  (display "; ")
  (display (y-point A))
  (display ")"))