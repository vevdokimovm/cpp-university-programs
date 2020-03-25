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

(define (make-rectangle p1 p2 p3 p4)
  (cons (cons p1 p2) (cons p3 p4)))

(define (first-segment rectangle)
  (car rectangle))

(define (second-segment rectangle)
  (cdr rectangle))

(define (square x) (* x x))

(define (length segment)
  (sqrt (+ (square (- (x-point (start-segment segment)) (x-point (end-segment segment))))
     (square (- (y-point (start-segment segment)) (y-point (end-segment segment)))))))

(define dx 0.00001)

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) dx))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))
 
(define (sqrt x)
  (fixed-point (lambda (y) (average y (/ x y)))
               1.0))

(define (area rectangle)
  (* (length (first-segment rectangle)) (length (second-segment rectangle))))

(define (perimetr rectangle)
  (* 2 (+ (length (first-segment rectangle)) (length (second-segment rectangle)))))