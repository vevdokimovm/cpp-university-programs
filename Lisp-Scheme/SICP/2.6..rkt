#lang racket

(define (square x) (* x x))

(define zero (lambda (f) (lambda (x) x)))

(define (add-1 n)
  (lambda (f) (lambda (x) (f ((n f) x)))))

(define one
  (lambda (f) (lambda (x) (f x))))

(define two
  (lambda (f) (lambda (x) (f (f x)))))

(define (inc a) (+ a 1))

(define (+ m n)
  (lambda (f) (lambda (x) (f ((m f) ((n f) x))))))