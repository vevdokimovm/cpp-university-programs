#lang racket

(define (identity x) x)

(define (inc x) (+ x 1))

(define (cube x) (* x x x))

(define (accumulation combine null-value term a next b)
  (if (> a b)
      null-value
      (combine (term a) (accumulation combine null-value term (next a) next b))))

(define (sum term a next b)
  (accumulation + 0 term a next b))

(define (product term a next b)
  (accumulation * 1 term a next b))

(define (factorial n)
  (product identity 1 inc n))

(define (sum-cubes a b)
  (sum cube a inc b))