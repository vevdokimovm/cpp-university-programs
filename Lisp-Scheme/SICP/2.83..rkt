#lang racket

(define (raise z) (apply-generic 'raise z))

;; Scheme-number package
(define (raise x)
  (make-rat x 1))
(put 'raise '(scheme-number) raise)

;; Rational pakcage
(define (raise x)
  (make-realis (/ (numer x)
                  (denom x))))
(put 'raise '(rational) raise)

;; Realis package
(define (raise x)
  (make-complex-from-real-imag (contents x) 0))
(put 'raise '(realis) raise)