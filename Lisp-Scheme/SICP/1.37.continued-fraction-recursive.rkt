#lang racket

(define (cont-frac n d k)
  (define (evaluation current k)
    (cond ((= k 0) (/ (n (- current 1)) (d (- current 1))))
          (else (/ (n current) (+ (d current) (evaluation (+ current 1) (- k 1)))))))
  (evaluation 1 k))